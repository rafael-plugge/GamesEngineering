#include "stdafx.h"
#include "PCharacterFactory.h"

std::unique_ptr<app::FactoryPattern::Drawable> app::FactoryPattern::PCharacterFactory::Create()
{
	return std::make_unique<PCharacter>();
}
