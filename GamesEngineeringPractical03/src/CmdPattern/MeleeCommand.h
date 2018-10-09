#ifndef _MELEE_COMMAND_H
#define _MELEE_COMMAND_H

#include "Command.h"

namespace app::cmd
{
	class MeleeCommand : public Command
	{
	public: // Constructors/Destructor/Assignments
		MeleeCommand() = default;
		MeleeCommand(MeleeCommand const &) = default;
		MeleeCommand(MeleeCommand &&) = default;

		~MeleeCommand() = default;

		MeleeCommand & operator=(MeleeCommand const &) = default;
		MeleeCommand & operator=(MeleeCommand &&) = default;

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

#endif // !_MELEE_COMMAND_H
