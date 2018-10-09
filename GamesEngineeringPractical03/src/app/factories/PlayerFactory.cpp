#include "stdafx.h"
#include "PlayerFactory.h"

// Components
#include "app/components/Player.h"
#include "app/components/Location.h"
#include "app/components/Dimension.h"
#include "app/components/Animation.h"
#include "app/components/Render.h"
#include "app/components/FiniteStateMachine.h"

#include "FSMPattern/PlayerStateMachine.h"

app::fact::PlayerFactory::PlayerFactory(app::Registry & registry, std::shared_ptr<SDL_Renderer> renderer)
	: EntityFactory(registry)
	, m_renderer(renderer)
{
}

app::Entity app::fact::PlayerFactory::create() const
{
	app::Entity entity = m_registry.create();

	m_registry.assign<comp::Player>(entt::tag_t(), entity);

	auto location = comp::Location();
	location.x = 0;
	location.y = 0;
	location.angle = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimension = comp::Dimension();
	dimension.width = 200;
	dimension.height = 200;
	m_registry.assign<decltype(dimension)>(entity, std::move(dimension));

	auto animation = comp::Animation();
	animation.currentFrame = 0u;
	animation.time = 0.0;
	animation.frames = {};
	animation.perFrame = 0;
	m_registry.assign<decltype(animation)>(entity, std::move(animation));

	auto render = comp::Render();
	render.texture = nullptr;
	render.source = { 0, 0, 199, 288 };
	m_registry.assign<decltype(render)>(entity, std::move(render));

	fsm::PlayerStateMachine::initStates(m_registry, m_renderer, entity);

	auto finiteStateMachine = comp::FiniteStateMachine();
	finiteStateMachine.stateMachine = std::make_unique<fsm::PlayerStateMachine>(m_registry);
	m_registry.assign<decltype(finiteStateMachine)>(entity, std::move(finiteStateMachine));

	return entity;
}
