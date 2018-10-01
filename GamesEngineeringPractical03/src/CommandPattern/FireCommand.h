#ifndef _FIRE_COMMAND_H
#define _FIRE_COMMAND_H

#include "Command.h"

namespace app::commandPattern
{
	class FireCommand : public Command
	{
	public: // Constructors/Destructor/Assignments
		FireCommand() = default;
		FireCommand(FireCommand const &) = default;
		FireCommand(FireCommand &&) = default;

		~FireCommand() = default;

		FireCommand & operator=(FireCommand const &) = default;
		FireCommand & operator=(FireCommand &&) = default;

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

#endif // !_FIRE_COMMAND_H
