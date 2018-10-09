#ifndef _ANIMATION_SOURCE_FACTORY_H
#define _ANIMATION_SOURCE_FACTORY_H

#include "app/factories/BaseFactory.h"

namespace app::fact
{
	class AnimationSourceFactory : public BaseFactory<std::vector<SDL_Rect>>
	{
	public: // Constructors/Destructor/Assignments
		constexpr AnimationSourceFactory() = default;
		AnimationSourceFactory(AnimationSourceFactory const &) = default;
		AnimationSourceFactory(AnimationSourceFactory &&) = default;

		~AnimationSourceFactory() = default;

		AnimationSourceFactory & operator=(AnimationSourceFactory const &) = default;
		AnimationSourceFactory & operator=(AnimationSourceFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
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

#endif // !_ANIMATION_SOURCE_FACTORY_H
