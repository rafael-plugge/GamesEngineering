#pragma once

#include "Drawable.h"

namespace app::FactoryPattern
{
	class PCharacter : public Drawable
	{
	public:
		PCharacter();
		~PCharacter() = default;
		virtual void draw() override;

	private:

	};

}