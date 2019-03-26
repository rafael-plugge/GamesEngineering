#include "stdafx.hpp"
#include "Cell.hpp"

void app::ent::Cell::init()
{
	if (m_entity) { m_entity->init(); }
}

void app::ent::Cell::update(app::time::seconds const & dt)
{
	if (m_entity) { m_entity->update(dt); }
}

void app::ent::Cell::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	if (m_entity) { m_entity->render(window, dt); }
}
