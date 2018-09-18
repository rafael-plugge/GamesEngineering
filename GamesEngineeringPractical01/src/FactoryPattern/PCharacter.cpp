#include "stdafx.h"
#include "PCharacter.h"

app::FactoryPattern::PCharacter::PCharacter()
{
	std::cout << "Creating Player Character" << std::endl;
}

void app::FactoryPattern::PCharacter::draw()
{
	std::cout << "Player character" << std::endl;
}
