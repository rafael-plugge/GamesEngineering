#ifndef _POSITION_COMPONENT_H
#define _POSITION_COMPONENT_H

#include "Component.h"

namespace app::comp
{
	struct PositionComponent : public Component
	{
	public: // Constructors/Destructor/Assignments
		PositionComponent() = default;
		PositionComponent(PositionComponent const &) = default;
		PositionComponent(PositionComponent &&) = default;

		~PositionComponent() = default;

		PositionComponent & operator=(PositionComponent const &) = default;
		PositionComponent & operator=(PositionComponent &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		float x = 0.0f, y = 0.0f;
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

#endif // !_POSITION_COMPONENT_H
