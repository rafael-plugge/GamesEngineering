#include "stdafx.h"
#include "StateMachine.h"

app::fsm::StateMachine::StateMachine(std::shared_ptr<State> state)
	: m_state(state)
{
}

void app::fsm::StateMachine::update(app::seconds const & dt)
{
	std::cout << "StateMachine::update -> " << dt.count() << std::endl;
}

void app::fsm::StateMachine::setState(std::shared_ptr<State> newState)
{
	if (m_state) { m_state->beforeChange(); }
	m_state = newState;
	if (m_state) { m_state->afterChange(); }
}
