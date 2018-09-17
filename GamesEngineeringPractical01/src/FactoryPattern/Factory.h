#pragma once

#include "Drawable.h"

namespace app
{
	class Factory
	{
	public:
		Factory() = default;
		~Factory() = default;
		virtual std::unique_ptr<Drawable> CreatePlayer() abstract;
		virtual std::unique_ptr<Drawable> CreateNpc() abstract;
	};

}