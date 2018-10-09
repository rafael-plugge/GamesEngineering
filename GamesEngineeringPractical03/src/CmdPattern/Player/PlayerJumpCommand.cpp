#include "stdafx.h"
#include "PlayerJumpCommand.h"

#include "app/factories/states/PlayerJumpStateFactory.h"

app::cmd::PlayerJumpCommand::PlayerJumpCommand(app::Registry & registry, app::Entity const entity)
	: PlayerCommand(registry, entity)
{
}

void app::cmd::PlayerJumpCommand::execute()
{
	PlayerCommand::execute();
}

void app::cmd::PlayerJumpCommand::undo()
{
	PlayerCommand::undo();
}

void app::cmd::PlayerJumpCommand::redo()
{
	PlayerCommand::redo();
}
