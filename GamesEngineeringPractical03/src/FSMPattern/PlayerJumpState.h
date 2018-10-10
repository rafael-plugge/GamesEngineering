#ifndef _FSM_PLAYER_JUMP_STATE_H
#define _FSM_PLAYER_JUMP_STATE_H

#include "PlayerState.h"

namespace app::fsm
{
	class PlayerJumpState : public PlayerState
	{
	public: // Constructors/Destructor/Assignments
		PlayerJumpState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> frames);

		PlayerJumpState(PlayerJumpState const &) = default;
		PlayerJumpState(PlayerJumpState &&) = default;

		~PlayerJumpState() = default;

		PlayerJumpState & operator=(PlayerJumpState const &) = default;
		PlayerJumpState & operator=(PlayerJumpState &&) = default;

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

#endif // !_FSM_PLAYER_JUMP_STATE_H
