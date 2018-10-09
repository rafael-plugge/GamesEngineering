#include "stdafx.h"
#include "PlayerIdleState.h"

app::fsm::PlayerIdleState::PlayerIdleState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> frames)
	: PlayerState(registry, entity, texture, frames)
{
}

void app::fsm::PlayerIdleState::update(app::seconds const & dt)
{
	PlayerState::update(dt);
}
