#ifndef _SHIELD_COMMAND_H
#define _SHIELD_COMMAND_H

#include "Command.h"

namespace app::commandPattern
{
	class ShieldCommand : public Command
	{
	public: // Constructors/Destructor/Assignments
		ShieldCommand() = default;
		ShieldCommand(ShieldCommand const &) = default;
		ShieldCommand(ShieldCommand &&) = default;

		~ShieldCommand() = default;

		ShieldCommand & operator=(ShieldCommand const &) = default;
		ShieldCommand & operator=(ShieldCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() override;
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

#endif // !_SHIELD_COMMAND_H
