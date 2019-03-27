#include "stdafx.hpp"
#include "Player.hpp"
#include "singletons/KeyHandlerSingleton.hpp"

app::math::Vector2f app::ent::Player::s_cellSizeFloat = math::Vector2f();

app::ent::Player::Player()
	: Entity()
	, m_position()
	, m_renderRect()
	, m_keyHandler(app::sin::KeyHandler::get())
{
}

app::ent::Player & app::ent::Player::operator=(Player const & other)
{
	Entity::operator=(other);
	this->m_position = other.m_position;
	this->m_renderRect = other.m_renderRect;
	return *this;
}

app::ent::Player & app::ent::Player::operator=(Player && other)
{
	Entity::operator=(other);
	this->m_position = std::move(other.m_position);
	this->m_renderRect = std::move(other.m_renderRect);
	return *this;
}

void app::ent::Player::init()
{
	s_cellSizeFloat = static_cast<math::Vector2f>(gra::Window::getSize()) * (1.0f / 100.0f);
	m_renderRect.setSize(static_cast<math::Vector2i>(s_cellSizeFloat));
	m_renderRect.setColor({ 0u, 255u, 0u });
	m_position = { 50u, 50u };
}

void app::ent::Player::update(app::time::seconds const & dt)
{
	if (m_keyHandler->isKeyDown({ SDLK_LEFT, SDLK_a }))
	{
		m_position.x -= 1u;
	}
	if (m_keyHandler->isKeyDown({ SDLK_RIGHT, SDLK_d }))
	{
		m_position.x += 1u;
	}
	if (m_keyHandler->isKeyDown({ SDLK_UP, SDLK_w }))
	{
		m_position.y -= 1u;
	}
	if (m_keyHandler->isKeyDown({ SDLK_DOWN, SDLK_s }))
	{
		m_position.y += 1u;
	}
}

void app::ent::Player::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	m_renderRect.setPosition(static_cast<math::Vector2i>(static_cast<math::Vector2f>(m_position) * s_cellSizeFloat));
	window.render(m_renderRect);
}
