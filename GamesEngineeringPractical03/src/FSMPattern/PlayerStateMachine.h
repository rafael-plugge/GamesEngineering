#ifndef _PLAYER_STATE_MACHINE_H
#define _PLAYER_STATE_MACHINE_H

#include "AnimationStateMachine.h"

namespace app::fsm
{
	class PlayerStateMachine : public AnimationStateMachine
	{
	public: // Constructors/Destructor/Assignments
		PlayerStateMachine(app::Registry & registry);

		PlayerStateMachine() = delete;
		PlayerStateMachine(PlayerStateMachine const &) = default;
		PlayerStateMachine(PlayerStateMachine &&) = default;

		~PlayerStateMachine() = default;

		PlayerStateMachine & operator=(PlayerStateMachine const &) = default;
		PlayerStateMachine & operator=(PlayerStateMachine &&) = default;

	public: // Public Static Functions
		static void initStates(app::Registry & registry, std::shared_ptr<SDL_Renderer> renderer, app::Entity const entity);
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

#endif // !_PLAYER_STATE_MACHINE_H
