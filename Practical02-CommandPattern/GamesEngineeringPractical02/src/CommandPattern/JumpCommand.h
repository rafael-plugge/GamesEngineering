#ifndef _JUMP_COMMAND_H
#define _JUMP_COMMAND_H

#include "Command.h"

namespace app::commandPattern
{
	class JumpCommand : public Command
	{
	public: // Constructors/Destructor/Assignments
		JumpCommand() = default;
		JumpCommand(JumpCommand const &) = default;
		JumpCommand(JumpCommand &&) = default;

		~JumpCommand() = default;

		JumpCommand & operator=(JumpCommand const &) = default;
		JumpCommand & operator=(JumpCommand &&) = default;

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

#endif // !_JUMP_COMMAND_H
