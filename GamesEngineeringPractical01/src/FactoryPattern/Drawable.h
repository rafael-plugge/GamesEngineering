#pragma once

namespace app
{
	class Drawable
	{
	public:
		Drawable() = default;
		~Drawable() = default;
		virtual void draw() abstract;
	};

}