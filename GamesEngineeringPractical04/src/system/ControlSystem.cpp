#include "stdafx.h"
#include "ControlSystem.h"

void app::sys::ControlSystem::update(app::time::nanoseconds const & dt)
{
	std::cout << "ControlSystem::update" << std::endl;
	app::sys::BaseSystem::update(dt);
}
