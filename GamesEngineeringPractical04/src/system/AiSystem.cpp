#include "stdafx.h"
#include "AiSystem.h"

app::sys::AiSystem::AiSystem()
	: BaseSystem()
{
}

void app::sys::AiSystem::update(app::time::nanoseconds const & dt)
{
	std::cout << "AiSystem update" << std::endl;
	app::sys::BaseSystem::update(dt);
}
