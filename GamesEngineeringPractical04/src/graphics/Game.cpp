#include "stdafx.h"
#include "Game.h"

// systems
#include "system/AiSystem.h"
#include "system/ControlSystem.h"
#include "system/RenderSystem.h"

app::gra::Game::Game()
	: m_gameLoop(true)
	, m_keyHandler()
	, m_mouseHandler()
	, m_window(m_keyHandler, m_mouseHandler, "Games Engineering Lab 4", app::WindowSize::width, app::WindowSize::height)
	, m_aiSystem()
{
}

app::gra::Game::~Game()
{
}

int app::gra::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	constexpr app::time::nanoseconds updateStep =
		app::time::toNanos(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	clock::time_point deltaTimePoint = clock::now();
	app::time::nanoseconds elapsedTime = updateStep;
	app::time::nanoseconds deltaRenderStep = app::time::nanoseconds::zero();

	if (!this->init()) { return EXIT_FAILURE; }
	while (m_gameLoop)
	{
		this->pollEvents();
		deltaRenderStep =
			(elapsedTime += app::time::toNanos(clock::now() - deltaTimePoint));
		deltaTimePoint = clock::now();
		while (elapsedTime > updateStep)
		{
			this->update(updateStep);
			elapsedTime -= updateStep;
		}
		this->render(deltaRenderStep);
	}

	return EXIT_SUCCESS;
}

bool app::gra::Game::init()
{
	return initEntities() && initSystems();
}

bool app::gra::Game::initEntities()
{


	return true;
}

bool app::gra::Game::initSystems()
{
	//m_aiSystem = app::sys::AiSystem();
	//m_controlSystem = app::sys::ControlSystem();
	//m_renderSystem = app::sys::RenderSystem();

	return true;
}

void app::gra::Game::pollEvents()
{
	m_window.pollEvents();
	m_gameLoop = m_window.isOpen();
}

void app::gra::Game::update(app::time::nanoseconds const & dt)
{
	//m_aiSystem.update(dt);
	//m_controlSystem.update(dt);
}

void app::gra::Game::render(app::time::nanoseconds const & dt)
{
	m_window.clear();
	//m_renderSystem.update(dt);
	m_window.display();
}

