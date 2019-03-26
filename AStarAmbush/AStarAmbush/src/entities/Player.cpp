#include "stdafx.hpp"
#include "Player.hpp"

void app::ent::Player::init()
{
	m_renderRect.setPosition({ 100.0, 100.0 });
	m_renderRect.setSize({ 100.0, 100.0 });
	auto texture = std::make_shared<gra::Texture>();
	m_renderRect.setTexture(texture);
}

void app::ent::Player::update(app::time::seconds const & dt)
{
}

void app::ent::Player::render(app::gra::Window const & window, app::time::seconds const & dt)
{
}
