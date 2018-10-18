#include "stdafx.h"
#include "RenderSystem.h"

void app::sys::RenderSystem::update(app::time::nanoseconds const & dt)
{
	if constexpr (s_includeRender)
	{
		std::cout << "RenderSystem::update" << std::endl;
		app::sys::BaseSystem::update(dt);
	}
}
