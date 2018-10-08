﻿#include "stdafx.h"
#include "Game.h"

// Systems
#include "app/system/InputKeySystem.h"
#include "app/system/InputMouseSystem.h"
#include "app/system/AnimationSystem.h"
#include "app/system/RenderSystem.h"

// commands
#include "CommandPattern/CrouchCommand.h"
#include "CommandPattern/FireCommand.h"
#include "CommandPattern/JumpCommand.h"
#include "CommandPattern/MeleeCommand.h"
#include "CommandPattern/ShieldCommand.h"

// Factories
#include "app/factories/TextureFactory.h"
#include "app/factories/PlayerIdleFactory.h"
#include "app/factories/PlayerFactory.h"

app::Game::Game()
	: m_registry()
	, m_keyhandler()
	, m_mousehandler()
	, m_window(m_keyhandler, m_mousehandler, "Games Engineering", 1366u, 768u)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != NULL)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL\nApplication failed to launch");
	}
}

app::Game::~Game()
{
	SDL_Quit();
}

int app::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	constexpr std::chrono::nanoseconds updateStepNano =
		std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	constexpr app::seconds updateStep = std::chrono::duration_cast<app::seconds>(updateStepNano);
	clock::time_point deltaTimePoint = clock::now();
	clock::duration elapsedTime = updateStepNano;
	clock::duration deltaRenderStep = clock::duration::zero();

	if (!this->init()) { return EXIT_FAILURE; }

	while (m_window.isOpen())
	{
		m_window.pollEvents();
		deltaRenderStep = elapsedTime += std::chrono::duration_cast<clock::duration>(clock::now() - deltaTimePoint);
		deltaTimePoint = clock::now();
		while (elapsedTime > updateStepNano)
		{
			this->update(updateStep);
			elapsedTime -= updateStepNano;
		}
		this->render(std::chrono::duration_cast<app::seconds>(deltaRenderStep));
	}

	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	return this->createComponentDependencies() && this->createSystems() && this->createEntities();
}

bool app::Game::createComponentDependencies()
{
	try
	{
		return true;
	}
	catch (const std::exception& e)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, e.what());
		return false;
	}
}

bool app::Game::createSystems()
{
	try
	{
		auto inputKeySystem = std::make_unique<sys::InputKeySystem>(sys::InputKeySystem(m_registry, m_keyhandler));
		inputKeySystem->bindCommand(SDLK_SPACE, std::make_unique<commandPattern::JumpCommand>());
		inputKeySystem->bindCommand(SDLK_c, std::make_unique<commandPattern::CrouchCommand>());
		inputKeySystem->bindCommand(SDLK_f, std::make_unique<commandPattern::MeleeCommand>());

		auto macroCommand = std::make_unique<commandPattern::MacroCommand>();
		macroCommand->add({ std::make_unique<commandPattern::CrouchCommand>(), std::make_unique<commandPattern::FireCommand>(), std::make_unique<commandPattern::ShieldCommand>() });
		inputKeySystem->bindCommand(SDLK_m, std::move(macroCommand));

		auto inputMouseSystem = std::make_unique<sys::InputMouseSystem>(m_registry, m_mousehandler);
		inputMouseSystem->bindCommand(util::MouseHandler::ButtonType::Left, std::make_unique<commandPattern::FireCommand>());
		inputMouseSystem->bindCommand(util::MouseHandler::ButtonType::Right, std::make_unique<commandPattern::ShieldCommand>());

		m_updateSystems = {
			std::move(inputKeySystem),
			std::move(inputMouseSystem)
		};

		m_renderSystems = {
			std::make_unique<sys::RenderSystem>(m_registry, m_window.getRenderer()),
			std::make_unique<sys::AnimationSystem>(m_registry)
		};

		return true;
	}
	catch (const std::exception& e)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, e.what());
		return false;
	}
}

bool app::Game::createEntities()
{
	std::shared_ptr<app::gra::Texture> playerTexture = app::fact::TextureFactory(m_window.getRenderer(), "./assets/player/player_idle.png").create();
	app::Entity const player = app::fact::PlayerFactory(m_registry, playerTexture, app::fact::PlayerIdleFactory().create()).create();
	return true;
}

void app::Game::update(app::seconds const & dt)
{
	std::for_each(m_updateSystems.begin(), m_updateSystems.end(),
		[&dt](std::unique_ptr<sys::BaseSystem> const & uptrSystem) { uptrSystem->update(dt); });
}

void app::Game::render(app::seconds const & dt)
{
	m_window.clear();
	std::for_each(m_renderSystems.begin(), m_renderSystems.end(),
		[&dt](std::unique_ptr<sys::BaseSystem> const & uptrSystem) { uptrSystem->update(dt); });
	m_window.display();
}