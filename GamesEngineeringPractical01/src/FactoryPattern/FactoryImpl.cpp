#include "stdafx.h"
#include "FactoryImpl.h"

std::unique_ptr<app::Drawable> app::FactoryImpl::CreatePlayer()
{
	return std::make_unique<PlayerCharacter>();
}

std::unique_ptr<app::Drawable> app::FactoryImpl::CreateNpc()
{
	return std::make_unique<Npc>();
}
