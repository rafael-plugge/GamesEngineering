#include "stdafx.h"
#include "Game.h"

// components
#include "component/PositionComponent.h"
#include "component/HealthComponent.h"
#include "component/ControlComponent.h"

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
	// create systems

	m_aiSystem = app::sys::AiSystem();
	m_controlSystem = app::sys::ControlSystem();
	m_renderSystem = app::sys::RenderSystem();

	// create entities
	
	// create player
	{
		auto player = app::ent::Entity();
		player.setName("Player");
		app::comp::Component c = app::comp::PositionComponent();
		c.setName("Position");
		player.addComp(c);
		c = app::comp::HealthComponent();
		c.setName("Health");
		player.addComp(c);
		c = app::comp::ControlComponent();
		c.setName("Control");
		player.addComp(c);

		m_controlSystem.addEntity(player);
		m_renderSystem.addEntity(player);
	}
	// create alien
	{
		auto alien = app::ent::Entity();
		alien.setName("Alien");
		app::comp::Component c = app::comp::PositionComponent();
		c.setName("Position");
		alien.addComp(c);
		c = app::comp::HealthComponent();
		c.setName("Health");
		alien.addComp(c);

		m_aiSystem.addEntity(alien);
		m_controlSystem.addEntity(alien);
		m_renderSystem.addEntity(alien);
	}
	// create dog
	{
		auto dog = app::ent::Entity();
		dog.setName("Dog");
		app::comp::Component c = app::comp::PositionComponent();
		c.setName("Position");
		dog.addComp(c);
		c = app::comp::HealthComponent();
		c.setName("Health");
		dog.addComp(c);

		m_aiSystem.addEntity(dog);
		m_controlSystem.addEntity(dog);
		m_renderSystem.addEntity(dog);
	}
	// create cat
	{
		auto cat = app::ent::Entity();
		cat.setName("Cat");
		app::comp::Component c = app::comp::PositionComponent();
		c.setName("Position");
		cat.addComp(c);
		c = app::comp::HealthComponent();
		c.setName("Health");
		cat.addComp(c);

		m_aiSystem.addEntity(cat);
		m_controlSystem.addEntity(cat);
		m_renderSystem.addEntity(cat);
	}
	return true;
}

void app::gra::Game::pollEvents()
{
	m_window.pollEvents();
	m_gameLoop = m_window.isOpen();
}

void app::gra::Game::update(app::time::nanoseconds const & dt)
{
	if (m_keyHandler.isKeyPressed(SDLK_SPACE))
	{
		m_aiSystem.update(dt);
		m_controlSystem.update(dt);
	}
	m_keyHandler.update();
}

void app::gra::Game::render(app::time::nanoseconds const & dt)
{
	m_window.clear();
	if (m_keyHandler.isKeyPressed(SDLK_SPACE)) { m_renderSystem.update(dt); }
	m_window.display();
}

