#ifndef _PLAYER_RUNNING_STATE_H
#define _PLAYER_RUNNING_STATE_H

#include "PlayerState.h"

namespace app::fsm
{
	class PlayerRunningState : public app::fsm::PlayerState
	{
	public: // Constructors/Destructor/Assignments
		PlayerRunningState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> frames);

		PlayerRunningState(PlayerRunningState const &) = default;
		PlayerRunningState(PlayerRunningState &&) = default;

		~PlayerRunningState() = default;

		PlayerRunningState & operator=(PlayerRunningState const &) = default;
		PlayerRunningState & operator=(PlayerRunningState &&) = default;

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

#endif // !_PLAYER_RUNNING_STATE_H
