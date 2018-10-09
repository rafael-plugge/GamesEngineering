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
#include "FSMPattern/PlayerIdleState.h"

#include "app/factories/TextureFactory.h"
#include "app/factories/states/PlayerIdleStateFactory.h"
#include "app/factories/states/PlayerJumpStateFactory.h"

app::fact::PlayerFactory::PlayerFactory(app::Registry & registry, std::shared_ptr<SDL_Renderer> renderer)
	: EntityFactory(registry)
	, m_renderer(renderer)
{
}

app::Entity app::fact::PlayerFactory::create() const
{
	app::Entity entity = m_registry.create();
	fsm::PlayerStateMachine::initStates(m_registry, m_renderer, entity);

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


	app::fact::PlayerJumpStateFactory(m_registry, entity,
		app::fact::TextureFactory(m_renderer, "./assets/player/player_jump_loop.png").create())
		.create();
	app::fact::PlayerIdleStateFactory(m_registry, entity,
		app::fact::TextureFactory(m_renderer, "./assets/player/player_idle.png").create())
		.create();

	/*
	auto finiteStateMachine = comp::FiniteStateMachine();
	auto playerStateMachine = std::make_unique<fsm::PlayerStateMachine>(m_registry);
	playerStateMachine->setState(app::fact::PlayerIdleStateFactory::instance());
	finiteStateMachine.stateMachine = std::move(playerStateMachine);
	m_registry.assign<decltype(finiteStateMachine)>(entity, std::move(finiteStateMachine));
	/**/

	return entity;
}
