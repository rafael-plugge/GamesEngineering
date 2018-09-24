#include "stdafx.h"
#include "NPCFactory.h"

std::unique_ptr<app::FactoryPattern::Drawable> app::FactoryPattern::NpcFactory::Create()
{
	return std::make_unique<Npc>();
}