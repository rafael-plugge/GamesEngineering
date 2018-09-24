#pragma once

#include "Factory.h"
#include "NPC.h"

namespace app::FactoryPattern
{
	class NpcFactory : public Factory
	{
	public:
		NpcFactory() = default;
		virtual std::unique_ptr<Drawable> Create() override;

	private:

	};

}