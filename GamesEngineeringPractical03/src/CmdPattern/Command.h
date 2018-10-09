#ifndef _COMMAND_H
#define _COMMAND_H

namespace app::cmd
{
	class Command
	{
	public: // Constructors/Destructor/Assignments
		Command(Command const &) = default;
		Command(Command &&) = default;

		virtual ~Command() = default;

		Command & operator=(Command const &) = default;
		Command & operator=(Command &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() abstract;
		virtual void undo() abstract;
		virtual void redo() abstract;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
		Command() = default;
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_COMMAND_H
