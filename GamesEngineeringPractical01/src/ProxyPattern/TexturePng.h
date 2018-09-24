#pragma once

#include "ITexture.h"

namespace app::ProxyPattern
{
	class TexturePng : public ITexture
	{
	public:
		TexturePng() = default;
		virtual bool load() override;

	private:

	};

}