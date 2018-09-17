#pragma once

#include "Factory.h"
#include "PlayerCharacter.h"
#include "NPC.h"

namespace app
{
	class FactoryImpl : public Factory
	{
	public:
		FactoryImpl() {}
		virtual std::unique_ptr<Drawable> CreatePlayer() override;
		virtual std::unique_ptr<Drawable> CreateNpc() override;
	};

}