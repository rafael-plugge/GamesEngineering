#include "stdafx.h"
#include "JumpCommand.h"

void app::commandPattern::JumpCommand::execute()
{
	std::cout << "Command: Jump" << std::endl;
}

void app::commandPattern::JumpCommand::undo()
{
	std::cout << "Undo Command: Jump" << std::endl;
}

void app::commandPattern::JumpCommand::redo()
{
	std::cout << "Redo Command: Jump" << std::endl;
}
