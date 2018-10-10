#include "stdafx.h"
#include "PlayerCommand.h"

app::cmd::PlayerCommand::PlayerCommand(app::Registry & registry, app::Entity const entity)
	: Command()
	, m_registry(registry)
	, m_entity(entity)
{
}

void app::cmd::PlayerCommand::execute()
{
	assert(m_registry.valid(m_entity));
	auto & finiteStateMachine = m_registry.get<comp::FiniteStateMachine>(m_entity);
	finiteStateMachine.stateMachine->setState(m_state);
}

void app::cmd::PlayerCommand::undo()
{
}

void app::cmd::PlayerCommand::redo()
{
}
