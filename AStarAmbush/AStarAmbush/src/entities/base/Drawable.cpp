#include "stdafx.hpp"
#include "Drawable.hpp"

app::ent::base::Drawable::Drawable()
	: Entity(0u)
	, m_renderRect()
{
}

void app::ent::base::Drawable::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	window.render(m_renderRect);
}
