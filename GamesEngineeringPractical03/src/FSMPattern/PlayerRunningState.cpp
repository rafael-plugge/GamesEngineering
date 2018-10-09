#include "stdafx.h"
#include "PlayerRunningState.h"

app::fsm::PlayerRunningState::PlayerRunningState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> frames)
	: PlayerState(registry, entity, texture, frames)
{
}

void app::fsm::PlayerRunningState::update(app::seconds const & dt)
{
	PlayerState::update(dt);
}
