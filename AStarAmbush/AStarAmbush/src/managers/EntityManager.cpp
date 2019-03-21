#include "stdafx.hpp"
#include "EntityManager.hpp"
// Entities
#include "entities/Grid.hpp"

bool app::man::EntityManager::init()
{
	m_entities.reserve(50);
	{
		auto grid = ent::Grid();
		m_entities.push_back(grid);
	}

	for (auto & entity : m_entities)
		std::visit([&](auto & ent) constexpr { ent.init(); }, entity);
	return true;
}

void app::man::EntityManager::update(app::time::seconds const & dt)
{
	for (auto & entity : m_entities)
		std::visit([&](auto & ent) { ent.update(dt); }, entity);
}

void app::man::EntityManager::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	for (auto & entity : m_entities)
		std::visit([&](auto & drawable) { drawable.render(window, dt); }, entity);
}
