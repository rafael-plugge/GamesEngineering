#pragma once

namespace app::HandlePattern
{
	class Window
	{
	public:
		Window() = default;
		virtual void Draw() = 0;
	};

}