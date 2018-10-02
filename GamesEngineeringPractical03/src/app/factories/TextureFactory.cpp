#include "stdafx.h"
#include "TextureFactory.h"

app::fact::TextureFactory::TextureFactory(std::shared_ptr<SDL_Renderer> renderer, std::string const & file)
	: BaseFactory()
	, m_renderer(renderer)
	, m_file(file)
{
}

std::shared_ptr<app::gra::Texture> app::fact::TextureFactory::create() const
{
	auto uptrTexture = std::make_unique<app::gra::Texture>();
	if (!uptrTexture->loadTexture(m_renderer, m_file)) { return nullptr; }
	return std::move(uptrTexture);
}
