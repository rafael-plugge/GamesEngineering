#pragma once

#include "entities/base/Entity.hpp"
#include "entities/base/Drawable.hpp"
#include "graphics/Window.hpp"

namespace app::man
{
	class EntityManager
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		EntityManager() = default;
		~EntityManager() = default;

		EntityManager(EntityManager const &) = default;
		EntityManager & operator=(EntityManager const &) = default;

		EntityManager(EntityManager &&) = default;
		EntityManager & operator=(EntityManager &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		bool init();
		void update(app::time::seconds const & dt) const;
		void render(app::gra::Window const & window, app::time::seconds const & dt) const;
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
		std::vector<std::shared_ptr<app::ent::base::Entity>> m_entities;
		std::vector<std::shared_ptr<app::ent::base::Drawable>> m_drawables;
	};

	static_assert(std::is_default_constructible<EntityManager>::value, "EntityManager must be default constructible");
	static_assert(std::is_destructible<EntityManager>::value, "EntityManager must be destructible");
	static_assert(std::is_copy_constructible<EntityManager>::value, "EntityManager must be copy constructible");
	static_assert(std::is_copy_assignable<EntityManager>::value, "EntityManager must be copy assignable");
	static_assert(std::is_move_constructible<EntityManager>::value, "EntityManager must be move constructible");
	static_assert(std::is_move_assignable<EntityManager>::value, "EntityManager must be move assignable");
}

