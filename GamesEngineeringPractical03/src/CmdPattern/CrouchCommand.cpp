#include "stdafx.h"
#include "CrouchCommand.h"

void app::cmd::CrouchCommand::execute()
{
	std::cout << "Command: Crouch" << std::endl;
}

void app::cmd::CrouchCommand::undo()
{
	std::cout << "Undo Command: Crouch" << std::endl;
}

void app::cmd::CrouchCommand::redo()
{
	std::cout << "Redo Command: Crouch" << std::endl;
}
