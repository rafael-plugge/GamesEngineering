#include "stdafx.h"
#include "AnimationStateMachine.h"

app::fsm::AnimationStateMachine::AnimationStateMachine(app::Registry & registry, std::shared_ptr<State> state)
	: StateMachine(state)
	, m_registry(registry)
{
}

/*
void app::fsm::AnimationStateMachine::player(app::Registry & registry, app::Entity entity)
{
	if (registry.valid(entity)) { m_entity = entity; }
	else { throw std::exception("Invalid entity in AnimationStateMachine::player"); }
}
/**/

void app::fsm::AnimationStateMachine::update(app::seconds const & dt)
{
	StateMachine::update(dt);
	if (!m_state) { return; }
	m_state->update(dt);
}
