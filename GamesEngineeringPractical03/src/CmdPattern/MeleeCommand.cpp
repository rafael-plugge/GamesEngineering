#include "stdafx.h"
#include "MeleeCommand.h"

void app::cmd::MeleeCommand::execute()
{
	std::cout << "Command: Melee" << std::endl;
}

void app::cmd::MeleeCommand::undo()
{
	std::cout << "Undo Command: Melee" << std::endl;
}

void app::cmd::MeleeCommand::redo()
{
	std::cout << "Redo Command: Melee" << std::endl;
}
