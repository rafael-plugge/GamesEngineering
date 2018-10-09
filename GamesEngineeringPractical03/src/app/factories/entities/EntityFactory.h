#ifndef _ENTITY_FACTORY_H
#define _ENTITY_FACTORY_H

#include "app/factories/BaseFactory.h"

namespace app::fact
{
	class EntityFactory : public BaseFactory<app::Entity>
	{
	public: // Constructors/Destructor/Assignments
		EntityFactory(app::Registry & registry);

		EntityFactory() = delete;
		EntityFactory(EntityFactory const &) = default;
		EntityFactory(EntityFactory &&) = default;

		~EntityFactory() = default;

		EntityFactory & operator=(EntityFactory const &) = default;
		EntityFactory & operator=(EntityFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity create() const abstract;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Registry & m_registry;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_ENTITY_FACTORY_H
