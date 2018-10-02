#include "stdafx.h"
#include "RenderSystem.h"

// Components
#include "app/components/Location.h"
#include "app/components/Dimension.h"
#include "app/components/Render.h"

app::sys::RenderSystem::RenderSystem(entt::DefaultRegistry & registry, std::shared_ptr<SDL_Renderer> renderer)
	: BaseSystem(registry)
	, m_renderer(renderer)
	, m_rect{ 0, 0, 0, 0 }
	, m_sourceRect()
{
}

void app::sys::RenderSystem::update(app::seconds const & dt)
{
	auto view = m_registry.view<comp::Location, comp::Dimension, comp::Render>();
	view.each([this](auto entity, comp::Location & location, comp::Dimension & dimension, comp::Render & render) -> void
	{
		if (!render.texture) { return; }

		m_rect.x = location.x;
		m_rect.y = location.y;
		m_rect.w = dimension.width;
		m_rect.h = dimension.height;

		SDL_RenderCopy(m_renderer.get(), render.texture->get(), m_sourceRect.has_value() ? &m_sourceRect.value() : nullptr, &m_rect);
	});
}
