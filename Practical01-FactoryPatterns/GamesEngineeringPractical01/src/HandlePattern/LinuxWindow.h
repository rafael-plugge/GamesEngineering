#pragma once

#include "Window.h"

namespace app::HandlePattern
{
	class LinuxWindow : public Window
	{
	public:
		LinuxWindow() = default;
		virtual void Draw() override;
	};

}