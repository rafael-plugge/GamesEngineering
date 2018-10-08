#include "stdafx.h"
#include "AnimationSystem.h"

// components
#include "app/components/Render.h"
#include "app/components/Animation.h"

app::sys::AnimationSystem::AnimationSystem(app::Registry & registry)
	: BaseSystem(registry)
{
}

void app::sys::AnimationSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::Render, comp::Animation>();
	view.each([&dt](app::Entity const entity, comp::Render & render, comp::Animation & animation)
	{
		animation.time += dt.count();
		while (animation.perFrame * static_cast<decltype(animation.perFrame)>(animation.currentFrame) < animation.time) { ++animation.currentFrame; }
		if (animation.currentFrame >= animation.frames.size()) { animation.currentFrame = 0u; animation.time = 0.0; }
		render.source = animation.frames.at(animation.currentFrame);
	});
}
