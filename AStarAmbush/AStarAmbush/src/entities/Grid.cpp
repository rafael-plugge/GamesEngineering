#include "stdafx.hpp"
#include "Grid.hpp"
#include "entities/Player.hpp"

void app::ent::Grid::init()
{
	{
		constexpr auto X = 0, Y = 0;
		auto player = std::make_shared<ent::Player>();
		m_grid.at(X).at(Y).set(player);
	}

	for (auto & col : m_grid)
		for (auto & cell : col)
			cell.init();
}

void app::ent::Grid::update(app::time::seconds const & dt)
{
	for (auto & col : m_grid)
		for (auto & cell : col)
			cell.update(dt);
}

void app::ent::Grid::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	for (auto & col : m_grid)
		for (auto & cell : col)
			cell.render(window, dt);
}
