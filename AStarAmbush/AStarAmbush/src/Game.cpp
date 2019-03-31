#include "stdafx.hpp"
#include "Game.hpp"
#include "singletons/KeyHandlerSingleton.hpp"
#include "singletons/ProcessQueueSingleton.hpp"

app::Game::Game()
	: m_running(true)
	, m_keyHandler(sin::KeyHandler::get())
	, m_processQueue(sin::ProcessQueue::get())
	, m_window()
	, m_grid()
{
}

app::Game::~Game()
{
}

bool app::Game::init()
{
	try
	{
		m_processQueue->init();
		m_window.init(*m_keyHandler, app::gra::WindowParameters{ "A* Ambush", 1366u, 768u });
		auto camera = gra::View();
		camera.size = { 1366, 768 };
		camera.position = camera.size / 2;
		m_window.setView(camera);
		m_grid.init();
		return true;
	}
	catch (std::exception const & e)
	{
		app::cout::wl({ "ERROR: ", e.what() });
		return false;
	}
}

void app::Game::pollEvents()
{
	m_window.pollEvents();
}

void app::Game::update(app::time::seconds const & dt)
{
	m_grid.update(dt);
	m_keyHandler->update();
}

void app::Game::render(app::time::seconds const & dt)
{
	m_window.clear();
	m_grid.render(m_window, dt);
	m_window.display();
}
