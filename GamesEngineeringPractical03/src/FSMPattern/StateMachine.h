#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

#include "State.h"

namespace app::fsm
{
	class StateMachine
	{
	public: // Constructors/Destructor/Assignments
		StateMachine(std::shared_ptr<State> state);

		StateMachine() = delete;
		StateMachine(StateMachine const &) = default;
		StateMachine(StateMachine &&) = default;

		~StateMachine() = default;

		StateMachine & operator=(StateMachine const &) = default;
		StateMachine & operator=(StateMachine &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::seconds const & dt);
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::shared_ptr<State> m_state;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_STATE_MACHINE_H
