#include "stdafx.h"
#include "TextureLoader.h"
#include "TexturePng.h"

std::unique_ptr<app::ProxyPattern::ITexture> app::ProxyPattern::TextureLoader::create() const
{
	return std::make_unique<TexturePng>();
}