#ifndef _PLAYER_RUNNING_FACTORY_H
#define _PLAYER_RUNNING_FACTORY_H

#include "SourceFactory.h"

namespace app::fact
{
	class PlayerRunningFactory : public AnimationSourceFactory
	{
	public: // Constructors/Destructor/Assignments
		PlayerRunningFactory() = default;
		PlayerRunningFactory(PlayerRunningFactory const &) = default;
		PlayerRunningFactory(PlayerRunningFactory &&) = default;

		~PlayerRunningFactory() = default;

		PlayerRunningFactory & operator=(PlayerRunningFactory const &) = default;
		PlayerRunningFactory & operator=(PlayerRunningFactory &&) = default;

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
