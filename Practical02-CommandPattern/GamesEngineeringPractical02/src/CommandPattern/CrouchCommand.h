#ifndef _CROUCH_COMMAND_H
#define _CROUCH_COMMAND_H

#include "Command.h"

namespace app::commandPattern
{
	class CrouchCommand : public Command
	{
	public: // Constructors/Destructor/Assignments
		CrouchCommand() = default;
		CrouchCommand(CrouchCommand const &) = default;
		CrouchCommand(CrouchCommand &&) = default;

		~CrouchCommand() = default;

		CrouchCommand & operator=(CrouchCommand const &) = default;
		CrouchCommand & operator=(CrouchCommand &&) = default;

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

#endif // !_CROUCH_COMMAND_H
