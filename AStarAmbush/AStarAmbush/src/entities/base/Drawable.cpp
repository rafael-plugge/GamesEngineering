#include "stdafx.hpp"
#include "Drawable.hpp"

void app::ent::base::Drawable::render(app::gra::Window const & window, app::time::seconds const & dt)
{
	window.render(m_renderRect);
}
