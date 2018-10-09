#include "stdafx.h"
#include "PlayerState.h"

// components
#include "app/components/Render.h"
#include "app/components/Animation.h"

app::fsm::PlayerState::PlayerState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> const & frames)
	: State()
	, m_registry(registry)
	, m_entity(entity)
	, m_texture(texture)
	, m_frames(frames)
{
	assert(m_registry.valid(m_entity) && texture && frames.size() > 0);
	if (!m_registry.has<app::comp::Render, app::comp::Animation>(entity)) { return; }
	this->applyTextureAndFrames();
}

void app::fsm::PlayerState::update(app::seconds const & dt)
{
	std::cout << "PlayerState::update" << std::endl;
}

void app::fsm::PlayerState::beforeChange()
{
}

void app::fsm::PlayerState::afterChange()
{
	if (!m_registry.has<app::comp::Render, app::comp::Animation>(m_entity)) { return; }
	this->applyTextureAndFrames();
}

void app::fsm::PlayerState::applyTextureAndFrames()
{
	auto[render, animation] = m_registry.get<comp::Render, comp::Animation>(m_entity);
	render.texture = m_texture;
	animation.frames = m_frames;
	if (m_frames.size() > 0) { animation.perFrame = 100.0 / m_frames.size(); }
}
