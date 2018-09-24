#pragma once

#include "Drawable.h"

namespace app::FactoryPattern
{
	class Npc : public Drawable
	{
	public:
		Npc();
		~Npc() = default;

		// Inherited via Drawable
		virtual void draw() override;

	private:

	};

}