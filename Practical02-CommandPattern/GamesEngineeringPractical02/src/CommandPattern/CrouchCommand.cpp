#include "stdafx.h"
#include "CrouchCommand.h"

void app::commandPattern::CrouchCommand::execute()
{
	std::cout << "Command: Crouch" << std::endl;
}

void app::commandPattern::CrouchCommand::undo()
{
	std::cout << "Undo Command: Crouch" << std::endl;
}

void app::commandPattern::CrouchCommand::redo()
{
	std::cout << "Redo Command: Crouch" << std::endl;
}
