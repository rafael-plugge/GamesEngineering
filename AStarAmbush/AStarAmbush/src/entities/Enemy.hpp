#pragma once

#include "base/Entity.hpp"

namespace app::ent
{
	class Enemy : public base::Entity
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Enemy() = default;
		virtual ~Enemy() = default;

		Enemy(Enemy const &) = default;
		Enemy & operator=(Enemy const &) = default;

		Enemy(Enemy &&) = default;
		Enemy & operator=(Enemy &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const & dt) final override;
		virtual void render(app::gra::Window const & window, app::time::seconds const & dt) final override;

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

	static_assert(std::is_default_constructible<Enemy>::value, "Enemy must be default constructible");
	static_assert(std::is_destructible<Enemy>::value, "Enemy must be destructible");
	static_assert(std::is_copy_constructible<Enemy>::value, "Enemy must be copy constructible");
	static_assert(std::is_copy_assignable<Enemy>::value, "Enemy must be copy assignable");
	static_assert(std::is_move_constructible<Enemy>::value, "Enemy must be move constructible");
	static_assert(std::is_move_assignable<Enemy>::value, "Enemy must be move assignable");
}
