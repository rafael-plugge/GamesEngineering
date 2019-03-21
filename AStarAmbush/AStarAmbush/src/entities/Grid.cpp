#include "stdafx.hpp"
#include "Grid.hpp"

app::ent::Grid::Grid()
	: Drawable()
	, m_grid()
{
}

void app::ent::Grid::update(app::time::seconds const & dt)
{
	app::cout::wl("Looping Grid:");
	for (size_t i = 0; i < m_grid.size(); i++)
	{
		auto const & row = m_grid.at(i);
		for (size_t col = 0; col < row.size(); col++)
		{
			auto const & cell = row.at(col);
			app::cout::wl({ "  Cell[", cell, "] (", i, ",", col, ")" });
		}
	}
}

void app::ent::Grid::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	Drawable::render(window, dt);
}
