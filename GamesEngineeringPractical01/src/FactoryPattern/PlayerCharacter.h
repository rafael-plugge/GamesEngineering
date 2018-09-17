#pragma once

#include "Drawable.h"

namespace app
{
	class PlayerCharacter : public Drawable
	{
	public:
		PlayerCharacter();
		~PlayerCharacter() = default;
		virtual void draw() override;

	private:

	};

}