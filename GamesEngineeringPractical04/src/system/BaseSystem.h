#ifndef _BASE_SYSTEM_H
#define _BASE_SYSTEM_H

#include "utilities/Time.h"
#include "entities/Entity.h"

namespace app::sys
{
	class BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		BaseSystem() = default;
		BaseSystem(BaseSystem const &) = default;
		BaseSystem(BaseSystem &&) = default;

		~BaseSystem() = default;

		BaseSystem & operator=(BaseSystem const &) = default;
		BaseSystem & operator=(BaseSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void addEntity(app::ent::Entity entity) { m_entities.push_back(entity); }
		virtual void remEntity(app::ent::Entity const & entity);
		virtual void update(app::time::nanoseconds const & dt);
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::vector<ent::Entity> m_entities;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		static constexpr bool s_includeComponents = false;
	private: // Private Member Variables
	};
}

#endif // !_BASE_SYSTEM_H
