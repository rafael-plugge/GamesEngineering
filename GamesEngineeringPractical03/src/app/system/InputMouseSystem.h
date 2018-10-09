#ifndef _INPUT_MOUSE_SYSTEM_H
#define _INPUT_MOUSE_SYSTEM_H

#include "BaseSystem.h"
#include "app/utilities/MouseHandler.h"
#include "CmdPattern/Command.h"

namespace app::sys
{
	class InputMouseSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		InputMouseSystem(app::Registry & registry, app::util::MouseHandler & mouseHandler);

		InputMouseSystem() = delete;
		InputMouseSystem(InputMouseSystem const &) = default;
		InputMouseSystem(InputMouseSystem &&) = default;

		~InputMouseSystem() = default;

		InputMouseSystem & operator=(InputMouseSystem const &) = default;
		InputMouseSystem & operator=(InputMouseSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void bindCommand(app::util::MouseHandler::ButtonType const & button, std::unique_ptr<cmd::Command> command);
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
		app::util::MouseHandler & m_mouseHandler;
		std::unordered_map<app::util::MouseHandler::ButtonType, std::unique_ptr<cmd::Command>> m_commands;
	};
}

#endif // !_INPUT_MOUSE_SYSTEM_H
