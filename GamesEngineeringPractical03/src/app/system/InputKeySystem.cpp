#include "stdafx.h"
#include "InputKeySystem.h"

// Components
#include "app/components/Location.h"
#include "app/components/Dimension.h"

app::sys::InputKeySystem::InputKeySystem(app::Registry & registry, app::util::KeyHandler<app::KeyCode> & keyHandler)
	: BaseSystem(registry)
	, m_keyHandler(keyHandler)
	, m_commands()
	, m_commandType(CommandType::Do)
{
}

void app::sys::InputKeySystem::bindCommand(app::KeyCode const & key, std::unique_ptr<app::commandPattern::Command> command)
{
	m_commands.insert({ key, std::move(command) });
}

void app::sys::InputKeySystem::update(app::seconds const & dt)
{
	if (m_keyHandler.isKeyPressed(SDLK_TAB)) { m_commandType = static_cast<CommandType>((static_cast<int>(m_commandType) + 1) % 3); }

	for (auto const &[key, command] : m_commands)
	{
		if (m_keyHandler.isKeyDown(key))
		{
			switch (m_commandType)
			{
			case app::sys::InputKeySystem::CommandType::Undo:
				command->undo();
				break;
			case app::sys::InputKeySystem::CommandType::Redo:
				command->redo();
				break;
			case app::sys::InputKeySystem::CommandType::Do:
			default:
				command->execute();
				break;
			}
		}
	}
	m_keyHandler.update();
}
