#include "stdafx.h"
#include "MeleeCommand.h"

void app::commandPattern::MeleeCommand::execute()
{
	std::cout << "Command: Melee" << std::endl;
}

void app::commandPattern::MeleeCommand::undo()
{
	std::cout << "Undo Command: Melee" << std::endl;
}

void app::commandPattern::MeleeCommand::redo()
{
	std::cout << "Redo Command: Melee" << std::endl;
}
