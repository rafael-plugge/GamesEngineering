#include "stdafx.h"
#include "BaseSystem.h"

void app::sys::BaseSystem::remEntity(app::ent::Entity const & entity)
{
	for (auto itt = std::begin(m_entities), end = std::end(m_entities); itt != end; ++itt)
	{
		if (itt->getId() == entity.getId()) { itt = m_entities.erase(itt); return; }
	}
}

void app::sys::BaseSystem::update(app::time::nanoseconds const & dt)
{
	for (auto & entity : m_entities)
	{
		std::cout << "  updating entity: " << entity.getName() << std::endl;
		for (auto & component : entity.getComps())
		{
			std::cout << "    component: " << component.getName() << std::endl;
		}
	}
}
