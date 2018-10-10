#ifndef _PLAYER_JUMP_FACTORY_H
#define _PLAYER_JUMP_FACTORY_H

#include "AnimationSourceFactory.h"

namespace app::fact
{
	class PlayerJumpSourceFactory : public AnimationSourceFactory
	{
	public: // Constructors/Destructor/Assignments
		constexpr PlayerJumpSourceFactory() = default;
		PlayerJumpSourceFactory(PlayerJumpSourceFactory const &) = default;
		PlayerJumpSourceFactory(PlayerJumpSourceFactory &&) = default;

		~PlayerJumpSourceFactory() = default;

		PlayerJumpSourceFactory & operator=(PlayerJumpSourceFactory const &) = default;
		PlayerJumpSourceFactory & operator=(PlayerJumpSourceFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::vector<SDL_Rect> create() const override;
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

#endif // !_PLAYER_JUMP_FACTORY_H
