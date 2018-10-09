#ifndef _FINTE_STATE_MACHINE_H
#define _FINTE_STATE_MACHINE_H

#include "FSMPattern/StateMachine.h"

namespace app::comp
{
	struct FiniteStateMachine
	{
	public: // Constructors/Destructor/Assignments
		FiniteStateMachine() = default;
		FiniteStateMachine(FiniteStateMachine const &) = default;
		FiniteStateMachine(FiniteStateMachine &&) = default;

		~FiniteStateMachine() = default;

		FiniteStateMachine & operator=(FiniteStateMachine const &) = default;
		FiniteStateMachine & operator=(FiniteStateMachine &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::unique_ptr<fsm::StateMachine> stateMachine;
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

#endif // !_FINTE_STATE_MACHINE_H
