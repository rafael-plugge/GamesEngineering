#include "stdafx.h"
#include "InputMouseSystem.h"

app::sys::InputMouseSystem::InputMouseSystem(app::Registry & registry, app::util::MouseHandler & mouseHandler)
	: BaseSystem(registry)
	, m_mouseHandler(mouseHandler)
	, m_commands()
{
}

void app::sys::InputMouseSystem::bindCommand(app::util::MouseHandler::ButtonType const & button, std::unique_ptr<commandPattern::Command> command)
{
	m_commands.insert({ button, std::move(command) });
}

void app::sys::InputMouseSystem::update(app::seconds const & dt)
{
	for (auto const &[key, command] : m_commands)
	{
		if (m_mouseHandler.isButtonDown(key)) { command->execute(); }
	}
}
