#include "stdafx.h"
#include "PlayerStateMachine.h"

// components
#include "app/components/Player.h"

// states
#include "PlayerIdleState.h"
#include "PlayerRunningState.h"

// factories
#include "app/factories/TextureFactory.h"
#include "app/factories/PlayerIdleFactory.h"
#include "app/factories/PlayerRunningFactory.h"

app::fsm::PlayerStateMachine::PlayerStateMachine(app::Registry & registry)
	: AnimationStateMachine(registry, PlayerIdleState::ptr())
{
}

void app::fsm::PlayerStateMachine::initStates(app::Registry & registry, std::shared_ptr<SDL_Renderer> renderer, app::Entity const entity)
{
	auto sptrRunningState = PlayerRunningState::ptr();
	sptrRunningState = std::make_shared<fsm::PlayerRunningState>(
		registry, entity,
		fact::TextureFactory(renderer, "./assets/player/player_running.png").create(),
		fact::PlayerRunningFactory().create()
	);
	auto sptrIdleState = PlayerIdleState::ptr();
	sptrIdleState = std::make_shared<fsm::PlayerIdleState>(
		registry, entity,
		fact::TextureFactory(renderer, "./assets/player/player_idle.png").create(),
		fact::PlayerIdleFactory().create()
	);
}

void app::fsm::PlayerStateMachine::update(app::seconds const & dt)
{
	AnimationStateMachine::update(dt);
}
