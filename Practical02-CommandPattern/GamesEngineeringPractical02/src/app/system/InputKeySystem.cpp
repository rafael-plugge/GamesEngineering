#include "stdafx.h"
#include "InputKeySystem.h"

// Components
#include "app/components/Location.h"
#include "app/components/Dimension.h"

app::sys::InputKeySystem::InputKeySystem(app::Registry & registry, app::util::KeyHandler<app::KeyCode> & keyHandler)
	: BaseSystem(registry)
	, m_keyHandler(keyHandler)
{
}

void app::sys::InputKeySystem::bindCommand(app::KeyCode const & key, std::unique_ptr<app::commandPattern::Command> command)
{
	m_commands.insert({ key, std::move(command) });
}

void app::sys::InputKeySystem::update(app::seconds const & dt)
{
	m_keyHandler.update();

	for (auto const &[key, command] : m_commands)
	{
		if (m_keyHandler.isKeyDown(key)) { command->execute(); }
	}
}
