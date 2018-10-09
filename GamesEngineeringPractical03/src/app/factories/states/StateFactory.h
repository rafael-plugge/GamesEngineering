#ifndef _STATE_FACTORY_H
#define _STATE_FACTORY_H

#include "app/factories/BaseFactory.h"
#include "app/graphics/Texture.h"
#include "FSMPattern/State.h"

namespace app::fact
{
	class StateFactory : public BaseFactory<std::shared_ptr<app::fsm::State>>
	{
	public: // Constructors/Destructor/Assignments
		StateFactory(app::Registry & registry, app::Entity const entity, std::shared_ptr<app::gra::Texture> texture);

		StateFactory(StateFactory const &) = default;
		StateFactory(StateFactory &&) = default;

		~StateFactory() = default;

		StateFactory & operator=(StateFactory const &) = default;
		StateFactory & operator=(StateFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Registry & m_registry;
		app::Entity const m_entity;
		std::shared_ptr<app::gra::Texture> m_texture;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_STATE_FACTORY_H
