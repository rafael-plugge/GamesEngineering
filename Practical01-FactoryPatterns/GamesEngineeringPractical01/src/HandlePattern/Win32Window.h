#pragma once

#include "Window.h"

namespace app::HandlePattern
{
	class Win32Window : public Window
	{
	public:
		Win32Window() = default;

		virtual void Draw() override;
	};

}