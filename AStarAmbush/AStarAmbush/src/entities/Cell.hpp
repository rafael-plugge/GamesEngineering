#pragma once

#include "base/Entity.hpp"

namespace app::ent
{
	class Cell : public base::Entity
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Cell() = default;
		virtual ~Cell() = default;

		Cell(Cell const &) = default;
		Cell & operator=(Cell const &) = default;

		Cell(Cell &&) = default;
		Cell & operator=(Cell &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const & dt) final override;
		virtual void render(app::gra::Window const & window, app::time::seconds const & dt) final override;
		void set(std::shared_ptr<app::ent::base::Entity> entity) { m_entity = entity; };
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::shared_ptr<app::ent::base::Entity> m_entity;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	static_assert(std::is_default_constructible<Cell>::value, "Cell must be default constructible");
	static_assert(std::is_destructible<Cell>::value, "Cell must be destructible");
	static_assert(std::is_copy_constructible<Cell>::value, "Cell must be copy constructible");
	static_assert(std::is_copy_assignable<Cell>::value, "Cell must be copy assignable");
	static_assert(std::is_move_constructible<Cell>::value, "Cell must be move constructible");
	static_assert(std::is_move_assignable<Cell>::value, "Cell must be move assignable");
}
