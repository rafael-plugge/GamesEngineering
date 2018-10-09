#include "stdafx.h"
#include "FireCommand.h"

void app::cmd::FireCommand::execute()
{
	std::cout << "Command: Fire" << std::endl;
}

void app::cmd::FireCommand::undo()
{
	std::cout << "Undo Command: Fire" << std::endl;
}

void app::cmd::FireCommand::redo()
{
	std::cout << "Redo Command: Fire" << std::endl;
}
