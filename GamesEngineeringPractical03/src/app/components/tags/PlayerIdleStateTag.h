#ifndef _PLAYER_IDLE_STATE_TAG_H
#define _PLAYER_IDLE_STATE_TAG_H

#include "FSMPattern/State.h"

namespace app::comp::tag
{
	struct PlayerIdleState
	{
	public: // Constructors/Destructor/Assignments
		PlayerIdleState() = default;
		PlayerIdleState(PlayerIdleState const &) = default;
		PlayerIdleState(PlayerIdleState &&) = default;

		~PlayerIdleState() = default;

		PlayerIdleState & operator=(PlayerIdleState const &) = default;
		PlayerIdleState & operator=(PlayerIdleState &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::shared_ptr<app::fsm::State> state;
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

#endif // !_PLAYER_IDLE_STATE_TAG_H
