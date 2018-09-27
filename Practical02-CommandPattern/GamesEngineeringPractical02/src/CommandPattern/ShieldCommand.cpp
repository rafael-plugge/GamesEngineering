#include "stdafx.h"
#include "ShieldCommand.h"

void app::commandPattern::ShieldCommand::execute()
{
	std::cout << "Command: Shield" << std::endl;
}

void app::commandPattern::ShieldCommand::undo()
{
	std::cout << "Undo Command: Shield" << std::endl;
}

void app::commandPattern::ShieldCommand::redo()
{
	std::cout << "Redo Command: Shield" << std::endl;
}
