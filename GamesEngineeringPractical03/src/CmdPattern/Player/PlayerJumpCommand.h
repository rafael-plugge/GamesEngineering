#ifndef _PLAYER_JUMP_COMMAND_H
#define _PLAYER_JUMP_COMMAND_H

#include "PlayerCommand.h"

namespace app::cmd
{
	class PlayerJumpCommand : public PlayerCommand
	{
	public: // Constructors/Destructor/Assignments
		PlayerJumpCommand(app::Registry & registry, app::Entity const entity);

		PlayerJumpCommand(PlayerJumpCommand const &) = default;
		PlayerJumpCommand(PlayerJumpCommand &&) = default;

		~PlayerJumpCommand() = default;

		PlayerJumpCommand & operator=(PlayerJumpCommand const &) = default;
		PlayerJumpCommand & operator=(PlayerJumpCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() override;
		virtual void undo() override;
		virtual void redo() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables


	};
}

#endif // !_PLAYER_JUMP_COMMAND_H
