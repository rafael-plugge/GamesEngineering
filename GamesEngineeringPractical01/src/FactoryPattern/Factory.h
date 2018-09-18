#pragma once

#include "Drawable.h"

namespace app::FactoryPattern
{
	class Factory
	{
	public:
		Factory() = default;
		~Factory() = default;
		virtual std::unique_ptr<Drawable> Create() = 0;
	};

}