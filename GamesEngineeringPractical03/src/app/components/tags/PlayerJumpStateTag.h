#ifndef _PLAYER_JUMP_STATE_TAG_H
#define _PLAYER_JUMP_STATE_TAG_H

#include "FSMPattern/State.h"

namespace app::comp::tag
{
	class PlayerJumpState
	{
	public: // Constructors/Destructor/Assignments
		PlayerJumpState() = default;
		PlayerJumpState(PlayerJumpState const &) = default;
		PlayerJumpState(PlayerJumpState &&) = default;

		~PlayerJumpState() = default;

		PlayerJumpState & operator=(PlayerJumpState const &) = default;
		PlayerJumpState & operator=(PlayerJumpState &&) = default;

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

#endif // !_PLAYER_JUMP_STATE_TAG_H
