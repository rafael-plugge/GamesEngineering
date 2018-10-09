#include "stdafx.h"
#include "PlayerState.h"

// components
#include "app/components/Render.h"
#include "app/components/Animation.h"

std::shared_ptr<app::fsm::PlayerState> app::fsm::PlayerState::s_ptr = nullptr;

app::fsm::PlayerState::PlayerState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> const & frames)
	: State()
	, m_registry(registry)
	, m_entity(entity)
	, m_texture(texture)
	, m_frames(frames)
{
	assert(m_registry.valid(m_entity));
	auto[render, animation] = m_registry.get<comp::Render, comp::Animation>(m_entity);
	render.texture = m_texture;
	animation.frames = frames;
	animation.perFrame = 100.0 / frames.size();
}

void app::fsm::PlayerState::update(app::seconds const & dt)
{
	std::cout << "PlayerState::update" << std::endl;
}
