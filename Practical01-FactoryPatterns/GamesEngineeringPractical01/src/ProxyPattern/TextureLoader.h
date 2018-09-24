#pragma once

#include "ITexture.h"

namespace app::ProxyPattern
{
	class TextureLoader
	{
	public:
		TextureLoader() = default;
		std::unique_ptr<ITexture> create() const;
	};

}