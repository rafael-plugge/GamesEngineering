#include "stdafx.hpp"
#include "Grid.hpp"
#include "entities/Player.hpp"

void app::ent::Grid::init()
{
	m_size = app::gra::Window::getSize();
	m_position = { 0, 0 };
	this->initLiveCells();
	this->initGrid();
}

void app::ent::Grid::update(app::time::seconds const & dt)
{
	for (auto & cell : m_liveCells)
		std::visit(util::overload{
			 [](std::monostate & c) constexpr {}
			,[&](auto & c) constexpr { c.update(dt); }
		}, cell);
}

void app::ent::Grid::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	std::for_each(m_liveCells.rbegin(), m_liveCells.rend(), [&](Grid::Cell & cell) constexpr
	{
		std::visit(util::overload{
			 [](std::monostate & c) constexpr {}
			,[&](auto & c) constexpr { c.render(window, dt); }
		}, cell);
	});
	this->renderGrid(window);
}

void app::ent::Grid::initLiveCells()
{
	m_liveCells.resize(NUMBER_ENEMIES + 1u);
	auto itt = m_liveCells.begin();
	*itt = ent::Player();
	app::ent::Enemy::setTarget([&]() -> app::ent::Player const &
	{
		auto const & player = std::get<ent::Player>(*itt);
		++itt;
		return player;
	}());
	for (auto i = 0u; i < NUMBER_ENEMIES; ++i, ++itt)
		*itt = ent::Enemy();


	auto enemyStartingPosition = math::Vector2u();
	for (auto & cell : m_liveCells)
	{
		std::visit(util::overload{
			 [](std::monostate & c) constexpr {}
			,[&](ent::Enemy & e)
			{
				e.init(enemyStartingPosition);
				if (enemyStartingPosition.x < GRID_WIDTH - 2)
					enemyStartingPosition.x += 2;
				else
				{
					enemyStartingPosition.x = 0;
					enemyStartingPosition.y += 2;
				}
			}
			,[](auto & c) constexpr { c.init(); }
		}, cell);
	}
}

void app::ent::Grid::initGrid()
{
	auto const & lineColor = gra::Color(math::Vector3<std::uint8_t>{ 255u, 255u, 255u });
	math::Vector2i start, end;
	start.y = 0; end.y = static_cast<std::int32_t>(m_size.y);
	m_verticalLines.reserve(GRID_WIDTH);
	for (std::size_t x = 1u; x < GRID_WIDTH; ++x)
	{
		auto const posX = static_cast<std::int32_t>(m_size.x * (x / static_cast<std::float_t>(GRID_WIDTH)));
		start.x = end.x = posX;
		auto renderLine = gra::RenderLine()
			.setStart(start)
			.setEnd(end)
			.setColor(lineColor);
		m_verticalLines.push_back(std::move(renderLine));
	}
	start.x = 0; end.x = static_cast<std::int32_t>(m_size.x);
	m_horizonalLines.reserve(GRID_HEIGHT);
	for (std::size_t y = 1u; y < GRID_HEIGHT; ++y)
	{
		auto const posY = static_cast<std::int32_t>(m_size.y * (y / static_cast<std::float_t>(GRID_HEIGHT)));
		start.y = end.y = posY;
		auto renderLine = gra::RenderLine()
			.setStart(start)
			.setEnd(end)
			.setColor(lineColor);
		m_horizonalLines.push_back(std::move(renderLine));
	}
}

void app::ent::Grid::renderGrid(app::gra::Window const & window)
{
	for (auto const & line : m_horizonalLines)
		window.render(line);
	for (auto const & line : m_verticalLines)
		window.render(line);
}
