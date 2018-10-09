#include "stdafx.h"
#include "JumpCommand.h"

void app::cmd::JumpCommand::execute()
{
	std::cout << "Command: Jump" << std::endl;
}

void app::cmd::JumpCommand::undo()
{
	std::cout << "Undo Command: Jump" << std::endl;
}

void app::cmd::JumpCommand::redo()
{
	std::cout << "Redo Command: Jump" << std::endl;
}
