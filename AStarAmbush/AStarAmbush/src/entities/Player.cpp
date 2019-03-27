#include "stdafx.hpp"
#include "Player.hpp"

app::math::Vector2f app::ent::Player::s_cellSize = math::Vector2f();

void app::ent::Player::init()
{
	s_cellSize = static_cast<math::Vector2f>(gra::Window::getSize()) * (1.0f / 100.0f);
	m_renderRect.setSize(static_cast<math::Vector2i>(s_cellSize));
	m_renderRect.setColor({ 255u, 0u, 0u });
	m_position = { 50u, 50u };
}

void app::ent::Player::update(app::time::seconds const & dt)
{
}

void app::ent::Player::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	m_renderRect.setPosition(static_cast<math::Vector2i>(static_cast<math::Vector2f>(m_position) * s_cellSize));
	window.render(m_renderRect);
}
