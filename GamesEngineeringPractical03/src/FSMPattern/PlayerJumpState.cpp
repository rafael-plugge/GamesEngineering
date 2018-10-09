#include "stdafx.h"
#include "PlayerJumpState.h"

app::fsm::PlayerJumpState::PlayerJumpState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> frames)
	: PlayerState(registry, entity, texture, frames)
{
}

void app::fsm::PlayerJumpState::update(app::seconds const & dt)
{
	app::fsm::PlayerState::update(dt);
}
