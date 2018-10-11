#include "stdafx.h"
#include "InputKeySystem.h"

// Components
#include "app/components/Player.h"
#include "app/components/Location.h"
#include "app/components/Dimension.h"

#include "CmdPattern/Player/PlayerJumpCommand.h"

app::sys::InputKeySystem::InputKeySystem(app::Registry & registry, app::util::KeyHandler<app::KeyCode> & keyHandler)
	: BaseSystem(registry)
	, m_keyHandler(keyHandler)
	, m_commands()
	, m_commandType(CommandType::Do)
{
	m_registry.construction<comp::Player>(entt::tag_t())
		.connect<app::sys::InputKeySystem, &app::sys::InputKeySystem::createJumpCommand>(this);
}

app::sys::InputKeySystem::~InputKeySystem()
{
	m_registry.construction<comp::Player>(entt::tag_t())
		.disconnect<app::sys::InputKeySystem, &app::sys::InputKeySystem::createJumpCommand>(this);
}

void app::sys::InputKeySystem::bindCommand(app::KeyCode const & key, std::unique_ptr<app::cmd::Command> command)
{
	m_commands.insert({ key, std::move(command) });
}

void app::sys::InputKeySystem::bindCommand(std::vector<std::pair<app::KeyCode const, std::unique_ptr<app::cmd::Command>>> commands)
{
	std::move(std::make_move_iterator(commands.begin()), std::make_move_iterator(commands.end()), std::inserter(m_commands, m_commands.end()));
}

void app::sys::InputKeySystem::createJumpCommand(app::Registry & registry, app::Entity entity)
{
	assert(registry.valid(entity));
	constexpr app::KeyCode jumpKey = SDLK_SPACE;
	std::unique_ptr<cmd::Command> jumpCommand = std::make_unique<cmd::PlayerJumpCommand>(registry, entity);
	decltype(m_commands)::iterator itt = m_commands.find(jumpKey);
	if (itt != m_commands.end()) { itt->second.swap(jumpCommand); }
	else { m_commands.insert(itt, { SDLK_SPACE, std::move(jumpCommand) }); }
}

void app::sys::InputKeySystem::update(app::seconds const & dt)
{
	if (m_keyHandler.isKeyPressed(SDLK_TAB)) { m_commandType = static_cast<CommandType>((static_cast<int>(m_commandType) + 1) % 2); }

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
