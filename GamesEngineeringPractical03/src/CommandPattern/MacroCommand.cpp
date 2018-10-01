#include "stdafx.h"
#include "MacroCommand.h"

void app::commandPattern::MacroCommand::add(std::shared_ptr<Command> command)
{
	m_commands.push_back(command);
}

void app::commandPattern::MacroCommand::add(std::vector<std::shared_ptr<Command>> commands)
{
	std::move(std::make_move_iterator(commands.begin()), std::make_move_iterator(commands.end()), std::back_inserter(m_commands));
}

void app::commandPattern::MacroCommand::remove(std::shared_ptr<Command> command)
{
	std::remove(m_commands.begin(), m_commands.end(), command);
}

void app::commandPattern::MacroCommand::execute()
{
	std::cout << "Macro Command Start:" << std::endl;
	std::for_each(m_commands.begin(), m_commands.end(), [](auto const & command) { command->execute(); });
	std::cout << "Macro Command End:" << std::endl;
}

void app::commandPattern::MacroCommand::undo()
{
	std::cout << "Macro Undo Command Start:" << std::endl;
	std::for_each(m_commands.begin(), m_commands.end(), [](auto const & command) { command->undo(); });
	std::cout << "Macro Undo Command End:" << std::endl;
}

void app::commandPattern::MacroCommand::redo()
{
	std::cout << "Macro Redo Command Start:" << std::endl;
	std::for_each(m_commands.begin(), m_commands.end(), [](auto const & command) { command->redo(); });
	std::cout << "Macro Redo Command End:" << std::endl;
}
