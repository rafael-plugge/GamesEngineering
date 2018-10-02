#include "stdafx.h"
#include "PlayerFactory.h"

// Components
#include "app/components/Location.h"
#include "app/components/Dimension.h"
#include "app/components/Render.h"

app::fact::PlayerFactory::PlayerFactory(app::Registry & registry, std::shared_ptr<app::gra::Texture> texture)
	: EntityFactory(registry)
	, m_texture(texture)
{
}

app::Entity app::fact::PlayerFactory::create() const
{
	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.x = 100;
	location.y = 100;
	location.angle = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimension = comp::Dimension();
	dimension.width = 200;
	dimension.height = 200;
	m_registry.assign<decltype(dimension)>(entity, std::move(dimension));

	auto render = comp::Render();
	render.texture = m_texture;

	return entity;
}
