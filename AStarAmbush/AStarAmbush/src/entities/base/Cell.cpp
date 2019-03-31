#include "stdafx.hpp"
#include "Cell.hpp"

app::math::Vector2f app::ent::base::Cell::s_cellSizeFloat = app::math::Vector2f();

void app::ent::base::Cell::init()
{
	s_cellSizeFloat = s_cellSizeFloat == app::math::Vector2f::zero
		? (static_cast<math::Vector2f>(gra::Window::getSize()) * (1.0f / 100.0f))
		: s_cellSizeFloat;
	m_renderRect.setSize(static_cast<math::Vector2i>(s_cellSizeFloat));
}

void app::ent::base::Cell::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	this->render(window);
}

void app::ent::base::Cell::render(app::gra::Window const & window)
{
	window.render(m_renderRect);
}

void app::ent::base::Cell::moveTo(std::uint32_t const & r, std::uint32_t const & c)
{
	this->moveTo(app::math::Vector2u{ r, c });
}

void app::ent::base::Cell::moveTo(math::Vector2u const & gridPosition)
{
	constexpr auto max = std::numeric_limits<decltype(math::Vector2u::zero)>::max();
	m_gridPosition = gridPosition;
	if (m_gridPosition.x > 99u) { m_gridPosition.x = 0u; }
	if (m_gridPosition.y > 99u) { m_gridPosition.y = 0u; }
	m_renderRect.setPosition(static_cast<math::Vector2i>(static_cast<math::Vector2f>(m_gridPosition) * s_cellSizeFloat));
}

void app::ent::base::Cell::move(std::int32_t const & r, std::int32_t const & c)
{
	this->move(app::math::Vector2i{ r, c });
}

void app::ent::base::Cell::move(math::Vector2i const & offset)
{
	auto const & newPosition = static_cast<math::Vector2i>(m_gridPosition) + offset;
	if (newPosition.x < 0) { newPosition.x = 99; }
	if (newPosition.y < 0) { newPosition.y = 99; }
	this->moveTo(static_cast<math::Vector2u>(newPosition));
}
