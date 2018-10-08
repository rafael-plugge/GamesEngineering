#include "stdafx.h"
#include "PlayerFactory.h"

// Components
#include "app/components/Location.h"
#include "app/components/Dimension.h"
#include "app/components/Animation.h"
#include "app/components/Render.h"

app::fact::PlayerFactory::PlayerFactory(app::Registry & registry, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> animation)
	: EntityFactory(registry)
	, m_texture(texture)
	, m_animation(std::move(animation))
{
}

app::Entity app::fact::PlayerFactory::create() const
{
	app::Entity entity = m_registry.create();

	auto location = comp::Location();
	location.x = 0;
	location.y = 0;
	location.angle = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimension = comp::Dimension();
	dimension.width = 200;
	dimension.height = 200;
	m_registry.assign<decltype(dimension)>(entity, std::move(dimension));

	auto animation = comp::Animation();
	animation.currentFrame = 0u;
	animation.time = 0.0;
	animation.frames = std::move(m_animation);
	animation.perFrame = 100.0 / animation.frames.size();
	m_registry.assign<decltype(animation)>(entity, std::move(animation));

	auto render = comp::Render();
	render.texture = m_texture;
	render.source = { 0, 0, 199, 288 };
	m_registry.assign<decltype(render)>(entity, std::move(render));

	return entity;
}
