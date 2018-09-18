#pragma once

#include "Character.h"
#include "Window.h"

namespace app::HandlePattern
{
	class PlayerCharacter : public Character
	{
	public:
		PlayerCharacter(std::shared_ptr<app::HandlePattern::Window> sptrWindow);

		virtual void Draw() override;

	private:
		std::shared_ptr<app::HandlePattern::Window> _sptrWindow;

	};

}