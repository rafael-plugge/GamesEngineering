#include "stdafx.h"
#include "ShieldCommand.h"

void app::cmd::ShieldCommand::execute()
{
	std::cout << "Command: Shield" << std::endl;
}

void app::cmd::ShieldCommand::undo()
{
	std::cout << "Undo Command: Shield" << std::endl;
}

void app::cmd::ShieldCommand::redo()
{
	std::cout << "Redo Command: Shield" << std::endl;
}
