#ifndef _CONTROL_COMPONENT_H
#define _CONTROL_COMPONENT_H

#include "Component.h"

namespace app::comp
{
	struct ControlComponent : public Component
	{
	public: // Constructors/Destructor/Assignments
		ControlComponent() = default;
		ControlComponent(ControlComponent const &) = default;
		ControlComponent(ControlComponent &&) = default;

		~ControlComponent() = default;

		ControlComponent & operator=(ControlComponent const &) = default;
		ControlComponent & operator=(ControlComponent &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		bool m_upArrowPressed;
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

#endif // !_CONTROL_COMPONENT_H
