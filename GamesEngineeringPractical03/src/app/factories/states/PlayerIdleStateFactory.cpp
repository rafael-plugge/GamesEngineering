#include "stdafx.h"
#include "PlayerIdleStateFactory.h"

#include "app/factories/animationSource/PlayerIdleSourceFactory.h"

#include "FSMPattern/PlayerIdleState.h"

#include "app/components/tags/PlayerIdleStateTag.h"

app::fact::PlayerIdleStateFactory::PlayerIdleStateFactory(app::Registry & registry, app::Entity const entity, std::shared_ptr<app::gra::Texture> texture)
	: StateFactory(registry, entity, texture)
{
}

std::shared_ptr<app::fsm::State> app::fact::PlayerIdleStateFactory::create() const
{
	auto playerIdleState = comp::tag::PlayerIdleState();
	playerIdleState.state = std::make_shared<app::fsm::PlayerIdleState>(
		m_registry, m_entity,
		m_texture,
		fact::PlayerIdleSourceFactory().create());
	m_registry.assign<decltype(playerIdleState)>(entt::tag_t(), m_registry.create(), playerIdleState);
	return playerIdleState.state;
}
