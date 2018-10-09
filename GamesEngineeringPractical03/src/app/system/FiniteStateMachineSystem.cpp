#include "stdafx.h"
#include "FiniteStateMachineSystem.h"

// components
#include "app/components/FiniteStateMachine.h"

app::sys::FiniteStateMachineSystem::FiniteStateMachineSystem(app::Registry & registry)
	: BaseSystem(registry)
{
}

void app::sys::FiniteStateMachineSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::FiniteStateMachine>();
	view.each([&dt](app::Entity const entity, comp::FiniteStateMachine & finiteStateMachine)
	{
		if (finiteStateMachine.stateMachine) { finiteStateMachine.stateMachine->update(dt); }
	});
}
