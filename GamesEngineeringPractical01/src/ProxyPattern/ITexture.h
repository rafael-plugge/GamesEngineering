#pragma once

namespace app::ProxyPattern
{
	class ITexture
	{
	public:
		ITexture() = default;
		virtual bool load() = 0;
	};

}