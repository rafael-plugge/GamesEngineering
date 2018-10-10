#ifndef _PLAYER_RUNNING_FACTORY_H
#define _PLAYER_RUNNING_FACTORY_H

#include "AnimationSourceFactory.h"

namespace app::fact
{
	class PlayerRunningSourceFactory : public AnimationSourceFactory
	{
	public: // Constructors/Destructor/Assignments
		PlayerRunningSourceFactory() = default;
		PlayerRunningSourceFactory(PlayerRunningSourceFactory const &) = default;
		PlayerRunningSourceFactory(PlayerRunningSourceFactory &&) = default;

		~PlayerRunningSourceFactory() = default;

		PlayerRunningSourceFactory & operator=(PlayerRunningSourceFactory const &) = default;
		PlayerRunningSourceFactory & operator=(PlayerRunningSourceFactory &&) = default;

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

#endif // !_PLAYER_RUNNING_FACTORY_H
