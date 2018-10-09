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
