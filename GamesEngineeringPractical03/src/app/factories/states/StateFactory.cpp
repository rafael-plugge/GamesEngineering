#include "stdafx.h"
#include "StateFactory.h"

app::fact::StateFactory::StateFactory(app::Registry & registry, app::Entity const entity, std::shared_ptr<app::gra::Texture> texture)
	: BaseFactory()
	, m_registry(registry)
	, m_entity(entity)
	, m_texture(texture)
{
}
