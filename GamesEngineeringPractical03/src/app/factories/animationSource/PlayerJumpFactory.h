#ifndef _PLAYER_JUMP_FACTORY_H
#define _PLAYER_JUMP_FACTORY_H

#include "SourceFactory.h"

namespace app::fact
{
	class PlayerJumpFactory : public AnimationSourceFactory
	{
	public: // Constructors/Destructor/Assignments
		constexpr PlayerJumpFactory() = default;
		PlayerJumpFactory(PlayerJumpFactory const &) = default;
		PlayerJumpFactory(PlayerJumpFactory &&) = default;

		~PlayerJumpFactory() = default;

		PlayerJumpFactory & operator=(PlayerJumpFactory const &) = default;
		PlayerJumpFactory & operator=(PlayerJumpFactory &&) = default;

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
