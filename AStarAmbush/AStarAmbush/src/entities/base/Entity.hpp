#pragma once

#include "graphics/Window.hpp"

namespace app::ent::base
{
	class Entity
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using TypeId = std::uint8_t;
	public: // Constructors/Destructor/Assignments
		Entity(TypeId const & id);
		virtual ~Entity() = default;

		Entity(Entity const &) = default;
		Entity & operator=(Entity const &) = default;

		Entity(Entity &&) = default;
		Entity & operator=(Entity &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr auto const & getId() const { return m_typeId; }
		virtual void update(app::time::seconds const & dt) abstract;
		virtual void render(app::gra::Window const & window, app::time::seconds const & dt) abstract;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		TypeId m_typeId;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	static_assert(std::is_destructible<Entity>::value, "Entity must be destructible");
	static_assert(std::is_copy_assignable<Entity>::value, "Entity must be copy assignable");
	static_assert(std::is_move_assignable<Entity>::value, "Entity must be move assignable");
}

