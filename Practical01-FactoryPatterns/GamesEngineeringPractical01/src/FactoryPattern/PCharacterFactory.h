#pragma once

#include "Factory.h"
#include "PCharacter.h"
#include "NPC.h"

namespace app::FactoryPattern
{
	class PCharacterFactory : public Factory
	{
	public:
		PCharacterFactory() {}
		virtual std::unique_ptr<Drawable> Create() override;
	};

}