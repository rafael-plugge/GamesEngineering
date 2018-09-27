#include "stdafx.h"
#include "Game.h"

// Systems
#include "app/system/RenderSystem.h"

app::Game::Game()
	: m_registry()
	, m_window("Games Engineering", 1366u, 768u)
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
	return this->createComponentDependencies() && this->createSystems();
}

bool app::Game::createComponentDependencies()
{
	return true;
}

bool app::Game::createSystems()
{
	try
	{
		m_updateSystems.reserve(5);
		m_renderSystems.reserve(1);

		m_renderSystems.push_back(std::make_unique<sys::RenderSystem>(sys::RenderSystem(m_registry, m_window.getRenderer())));

		return true;
	}
	catch (const std::exception& e)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, e.what());
		return false;
	}
}

void app::Game::update(app::seconds const & dt)
{
	std::for_each(m_updateSystems.begin(), m_updateSystems.end(),
		[&dt](std::unique_ptr<sys::BaseSystem> & uptrSystem) { uptrSystem->update(dt); });
}

void app::Game::render(app::seconds const & dt)
{
	m_window.clear();
	std::for_each(m_renderSystems.begin(), m_renderSystems.end(),
		[&dt](std::unique_ptr<sys::BaseSystem> & uptrSystem) { uptrSystem->update(dt); });
	m_window.display();
}
