#ifndef _ANIMATION_SYSTEM_H
#define _ANIMATION_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class AnimationSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AnimationSystem(app::Registry & registry);

		AnimationSystem() = delete;
		AnimationSystem(AnimationSystem const &) = default;
		AnimationSystem(AnimationSystem &&) = default;

		~AnimationSystem() = default;

		AnimationSystem & operator=(AnimationSystem const &) = default;
		AnimationSystem & operator=(AnimationSystem &&) = default;

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

#endif // !_ANIMATION_SYSTEM_H
