#include "stdafx.hpp"
#include "Entity.hpp"

app::ent::base::Entity::Entity(Entity::TypeId const & id)
	: m_typeId(id)
{
}
