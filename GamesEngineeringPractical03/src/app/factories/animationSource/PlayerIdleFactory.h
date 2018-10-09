#ifndef _PLAYER_IDLE_FACTORY_H
#define _PLAYER_IDLE_FACTORY_H

#include "SourceFactory.h"

namespace app::fact
{
	class PlayerIdleFactory : public AnimationSourceFactory
	{
	public: // Constructors/Destructor/Assignments
		constexpr PlayerIdleFactory() = default;
		PlayerIdleFactory(PlayerIdleFactory const &) = default;
		PlayerIdleFactory(PlayerIdleFactory &&) = default;

		~PlayerIdleFactory() = default;

		PlayerIdleFactory & operator=(PlayerIdleFactory const &) = default;
		PlayerIdleFactory & operator=(PlayerIdleFactory &&) = default;

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
