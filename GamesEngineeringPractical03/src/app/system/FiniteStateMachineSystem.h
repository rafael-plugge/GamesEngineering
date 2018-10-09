#ifndef _FINITE_STATE_MACHINE_H
#define _FINITE_STATE_MACHINE_H

#include "BaseSystem.h"

namespace app::sys
{
	class FiniteStateMachineSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		FiniteStateMachineSystem(app::Registry & registry);

		FiniteStateMachineSystem(FiniteStateMachineSystem const &) = default;
		FiniteStateMachineSystem(FiniteStateMachineSystem &&) = default;

		~FiniteStateMachineSystem() = default;

		FiniteStateMachineSystem & operator=(FiniteStateMachineSystem const &) = default;
		FiniteStateMachineSystem & operator=(FiniteStateMachineSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
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

	};
}

#endif // !_FINITE_STATE_MACHINE_H
