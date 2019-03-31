#include "stdafx.hpp"
#include "Player.hpp"
#include "singletons/KeyHandlerSingleton.hpp"

app::ent::Player::Player()
	: Cell()
	, m_keyHandler(app::sin::KeyHandler::get())
{
}

app::ent::Player & app::ent::Player::operator=(Player const & other)
{
	Cell::operator=(other);
	return *this;
}

app::ent::Player & app::ent::Player::operator=(Player && other)
{
	Cell::operator=(other);
	return *this;
}

void app::ent::Player::init()
{
	Cell::init();
	this->setColor({ 0u, 255u, 0u });
	this->moveTo({ 50, 50 });
}

void app::ent::Player::update(app::time::seconds const & dt)
{
	if (m_keyHandler->isKeyPressed(SDLK_LEFT) || m_keyHandler->isKeyDown(SDLK_a))
	{
		this->move(-1, 0);
	}
	if (m_keyHandler->isKeyPressed(SDLK_RIGHT) || m_keyHandler->isKeyDown(SDLK_d))
	{
		this->move(1, 0);
	}
	if (m_keyHandler->isKeyPressed(SDLK_UP) || m_keyHandler->isKeyDown(SDLK_w))
	{
		this->move(0, -1);
	}
	if (m_keyHandler->isKeyPressed(SDLK_DOWN) || m_keyHandler->isKeyDown(SDLK_s))
	{
		this->move(0, 1);
	}
}
