#pragma once

namespace app::FactoryPattern
{
	class Drawable
	{
	public:
		Drawable() = default;
		~Drawable() = default;
		virtual void draw() abstract;
	};

}