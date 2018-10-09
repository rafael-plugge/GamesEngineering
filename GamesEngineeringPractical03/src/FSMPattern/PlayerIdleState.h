#ifndef _PLAYER_IDLE_STATE_H
#define _PLAYER_IDLE_STATE_H

#include "PlayerState.h"

namespace app::fsm
{
	class PlayerIdleState : public app::fsm::PlayerState
	{
	public: // Constructors/Destructor/Assignments
		PlayerIdleState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> frames);

		PlayerIdleState(PlayerIdleState const &) = default;
		PlayerIdleState(PlayerIdleState &&) = default;

		~PlayerIdleState() = default;

		PlayerIdleState & operator=(PlayerIdleState const &) = default;
		PlayerIdleState & operator=(PlayerIdleState &&) = default;

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

#endif // !_PLAYER_IDLE_STATE_H
