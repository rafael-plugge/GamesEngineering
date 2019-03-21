#include "stdafx.hpp"
#include "EntityManager.hpp"
// Entities
#include "entities/Grid.hpp"

bool app::man::EntityManager::init()
{
	m_entities.reserve(50);
	{
		auto grid = std::make_shared<ent::Grid>();
		grid->setPosition({ 0.0, 0.0 });
		grid->setSize(math::Vector2d{} * ent::Grid::GRID_SIZE);
		grid->setOrigin({});
		m_drawables.push_back(grid);
		m_entities.push_back(m_drawables.back());
	}
	return true;
}

void app::man::EntityManager::update(app::time::seconds const & dt) const
{
	for (auto const & sptr : m_entities) { sptr->update(dt); }
}

void app::man::EntityManager::render(app::gra::Window const & window, app::time::seconds const & dt) const
{
}
