#include "stdafx.h"
#include "FireCommand.h"

void app::commandPattern::FireCommand::execute()
{
	std::cout << "Command: Fire" << std::endl;
}

void app::commandPattern::FireCommand::undo()
{
	std::cout << "Undo Command: Fire" << std::endl;
}

void app::commandPattern::FireCommand::redo()
{
	std::cout << "Redo Command: Fire" << std::endl;
}
