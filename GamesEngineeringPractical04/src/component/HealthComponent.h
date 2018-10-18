#ifndef _HEALTH_COMPONENT_H
#define _HEALTH_COMPONENT_H

#include "Component.h"

namespace app::comp
{
	struct HealthComponent : public app::comp::Component
	{
	public: // Constructors/Destructor/Assignments
		HealthComponent() = default;
		HealthComponent(HealthComponent const &) = default;
		HealthComponent(HealthComponent &&) = default;

		~HealthComponent() = default;

		HealthComponent & operator=(HealthComponent const &) = default;
		HealthComponent & operator=(HealthComponent &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		float health;
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

#endif // !_HEALTH_COMPONENT_H
