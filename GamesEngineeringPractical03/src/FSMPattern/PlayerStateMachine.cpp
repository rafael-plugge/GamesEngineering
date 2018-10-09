#include "stdafx.h"
#include "PlayerStateMachine.h"

// components
#include "app/components/Player.h"

// states
#include "PlayerIdleState.h"
#include "PlayerRunningState.h"
#include "PlayerJumpState.h"

// factories
#include "app/factories/TextureFactory.h"
#include "app/factories/animationSource/PlayerIdleFactory.h"
#include "app/factories/animationSource/PlayerRunningFactory.h"
#include "app/factories/animationSource/PlayerJumpFactory.h"

app::fsm::PlayerStateMachine::PlayerStateMachine(app::Registry & registry)
	: AnimationStateMachine(registry, nullptr)
{
}

void app::fsm::PlayerStateMachine::initStates(app::Registry & registry, std::shared_ptr<SDL_Renderer> renderer, app::Entity const entity)
{
	/*
	auto & sptrJumpState = PlayerJumpState::ptr();
	sptrJumpState = std::make_shared<fsm::PlayerJumpState>(
		registry, entity,
		fact::TextureFactory(renderer, "./assets/player/player_jump_loop.png").create(),
		fact::PlayerJumpFactory().create()
	);
	auto & sptrRunningState = PlayerRunningState::ptr();
	sptrRunningState = std::make_shared<fsm::PlayerRunningState>(
		registry, entity,
		fact::TextureFactory(renderer, "./assets/player/player_running.png").create(),
		fact::PlayerRunningFactory().create()
	);
	auto & sptrIdleState = PlayerIdleState::ptr();
	sptrIdleState = std::make_shared<fsm::PlayerIdleState>(
		registry, entity,
		fact::TextureFactory(renderer, "./assets/player/player_idle.png").create(),
		fact::PlayerIdleFactory().create()
	);
	/**/
}

void app::fsm::PlayerStateMachine::update(app::seconds const & dt)
{
	AnimationStateMachine::update(dt);
}
