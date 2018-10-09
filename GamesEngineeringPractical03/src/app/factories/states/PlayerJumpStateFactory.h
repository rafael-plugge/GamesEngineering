#ifndef _PLAYER_JUMP_STATE_FACTORY_H
#define _PLAYER_JUMP_STATE_FACTORY_H

#include "StateFactory.h"

namespace app::fact
{
	class PlayerJumpStateFactory : public StateFactory
	{
	public: // Constructors/Destructor/Assignments
		PlayerJumpStateFactory(app::Registry & registry, app::Entity const entity, std::shared_ptr<app::gra::Texture> texture);

		PlayerJumpStateFactory(PlayerJumpStateFactory const &) = default;
		PlayerJumpStateFactory(PlayerJumpStateFactory &&) = default;

		~PlayerJumpStateFactory() = default;

		PlayerJumpStateFactory & operator=(PlayerJumpStateFactory const &) = default;
		PlayerJumpStateFactory & operator=(PlayerJumpStateFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::shared_ptr<app::fsm::State> create() const override;
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

#endif // !_PLAYER_JUMP_STATE_FACTORY_H
