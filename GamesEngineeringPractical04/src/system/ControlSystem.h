﻿#ifndef _CONTROL_SYSTEM_H
#define _CONTROL_SYSTEM_H

#include "system/BaseSystem.h"

namespace app::sys
{
	class ControlSystem : public app::sys::BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		ControlSystem() = default;
		ControlSystem(ControlSystem const &) = default;
		ControlSystem(ControlSystem &&) = default;

		~ControlSystem() = default;

		ControlSystem & operator=(ControlSystem const &) = default;
		ControlSystem & operator=(ControlSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::nanoseconds const & dt) override;
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

#endif // !_CONTROL_SYSTEM_H
