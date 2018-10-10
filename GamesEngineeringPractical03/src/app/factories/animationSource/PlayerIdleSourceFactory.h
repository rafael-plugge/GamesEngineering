#ifndef _PLAYER_IDLE_FACTORY_H
#define _PLAYER_IDLE_FACTORY_H

#include "AnimationSourceFactory.h"

namespace app::fact
{
	class PlayerIdleSourceFactory : public AnimationSourceFactory
	{
	public: // Constructors/Destructor/Assignments
		constexpr PlayerIdleSourceFactory() = default;
		PlayerIdleSourceFactory(PlayerIdleSourceFactory const &) = default;
		PlayerIdleSourceFactory(PlayerIdleSourceFactory &&) = default;

		~PlayerIdleSourceFactory() = default;

		PlayerIdleSourceFactory & operator=(PlayerIdleSourceFactory const &) = default;
		PlayerIdleSourceFactory & operator=(PlayerIdleSourceFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::vector<SDL_Rect> create() const final override;
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

#endif // !_PLAYER_IDLE_FACTORY_H
