#include "stdafx.h"
#include "PlayerJumpStateFactory.h"

#include "FSMPattern/PlayerJumpState.h"
#include "app/factories/animationSource/PlayerJumpFactory.h"
#include "app/components/tags/PlayerJumpStateTag.h"

app::fact::PlayerJumpStateFactory::PlayerJumpStateFactory(app::Registry & registry, app::Entity const entity, std::shared_ptr<app::gra::Texture> texture)
	: StateFactory(registry, entity, texture)
{
}

std::shared_ptr<app::fsm::State> app::fact::PlayerJumpStateFactory::create() const
{
	/*
	auto playerIdleState = comp::tag::PlayerIdleState();
	playerIdleState.state = std::make_shared<app::fsm::PlayerIdleState>(
		m_registry, m_entity,
		m_texture,
		fact::PlayerIdleFactory().create());
	m_registry.assign<comp::tag::PlayerIdleState>(entt::tag_t(), m_registry.create(), playerIdleState);
	return playerIdleState.state;
	*/
	auto playerJumpState = comp::tag::PlayerJumpState();
	playerJumpState.state = std::make_shared<app::fsm::PlayerJumpState>(
		m_registry, m_entity, m_texture,
		fact::PlayerJumpFactory().create());
	m_registry.assign<decltype(playerJumpState)>(entt::tag_t(), m_registry.create(), playerJumpState);
	return playerJumpState.state;
}
