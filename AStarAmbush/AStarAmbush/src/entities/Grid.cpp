#include "stdafx.hpp"
#include "Grid.hpp"

void app::ent::Grid::init()
{
	m_size = app::gra::Window::getSize();
	m_position = { 0, 0 };
}

void app::ent::Grid::update(app::time::seconds const & dt)
{
}

void app::ent::Grid::render(app::gra::Window const & window, app::time::seconds const & dt)
{

}
