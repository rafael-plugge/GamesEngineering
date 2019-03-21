#include "stdafx.hpp"
#include "Game.hpp"

app::Game::Game()
	: m_running(true)
	, m_keyHandler()
	, m_mouseHandler()
	, m_controllerHandler()
	, m_window(m_keyHandler, m_mouseHandler, m_controllerHandler, app::gra::WindowParameters{ "A* Ambush", 1366u, 768u })
{
}

app::Game::~Game()
{
}

bool app::Game::init()
{
	try
	{
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
}

void app::Game::render(app::time::seconds const & dt)
{
	m_window.clear();
	m_window.display();
}
