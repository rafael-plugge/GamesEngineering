#ifndef _MACRO_COMMAND_H
#define _MACRO_COMMAND_H

#include "Command.h"

namespace app::commandPattern
{
	class MacroCommand : public Command
	{
	public: // Constructors/Destructor/Assignments
		MacroCommand() = default;
		MacroCommand(MacroCommand const &) = delete;
		MacroCommand(MacroCommand &&) = default;

		~MacroCommand() = default;

		MacroCommand & operator=(MacroCommand const &) = delete;
		MacroCommand & operator=(MacroCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void add(std::shared_ptr<Command> command);
		virtual void add(std::vector<std::shared_ptr<Command>> commands);
		virtual void remove(std::shared_ptr<Command> command);
		virtual void execute() override;
		virtual void undo() override;
		virtual void redo() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::vector<std::shared_ptr<Command>> m_commands;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_MACRO_COMMAND_H
