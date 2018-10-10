#include "stdafx.h"
#include "PlayerJumpCommand.h"

#include "app/factories/states/PlayerJumpStateFactory.h"

#include "app/components/tags/PlayerJumpStateTag.h"
#include "app/components/tags/PlayerIdleStateTag.h"

app::cmd::PlayerJumpCommand::PlayerJumpCommand(app::Registry & registry, app::Entity const entity)
	: PlayerCommand(registry, entity)
{
}

void app::cmd::PlayerJumpCommand::execute()
{
	auto & state = this->getComp<comp::FiniteStateMachine>();
	auto & jumpState = this->getCompTag<comp::tag::PlayerJumpState>();
	state.stateMachine->setState(jumpState.state);
}

void app::cmd::PlayerJumpCommand::undo()
{
	auto & state = this->getComp<comp::FiniteStateMachine>();
	auto & idleState = this->getCompTag<comp::tag::PlayerIdleState>();
	state.stateMachine->setState(idleState.state);
}

void app::cmd::PlayerJumpCommand::redo()
{
	PlayerCommand::redo();
}
