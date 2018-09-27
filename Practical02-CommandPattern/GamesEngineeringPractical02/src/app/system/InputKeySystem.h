#ifndef _INPUT_KEY_SYSTEM_H
#define _INPUT_KEY_SYSTEM_H

#include "BaseSystem.h"
#include "app/utilities/Keyhandler.h"
#include "app/utilities/MouseHandler.h"
#include "CommandPattern/Command.h"

namespace app::sys
{
	class InputKeySystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		InputKeySystem(app::Registry & registry, app::util::KeyHandler<app::KeyCode> & keyHandler);

		InputKeySystem() = delete;
		InputKeySystem(InputKeySystem const &) = default;
		InputKeySystem(InputKeySystem &&) = default;

		~InputKeySystem() = default;

		InputKeySystem & operator=(InputKeySystem const &) = default;
		InputKeySystem & operator=(InputKeySystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void bindCommand(app::KeyCode const & key, std::unique_ptr<app::commandPattern::Command> command);
		virtual void update(app::seconds const & dt) override;
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
		app::util::KeyHandler<app::KeyCode> & m_keyHandler;
		std::unordered_map<app::KeyCode, std::unique_ptr<app::commandPattern::Command>> m_commands;
	};
}

#endif // !_INPUT_KEY_SYSTEM_H
