#pragma once

#include "Entity.hpp"

namespace app::ent::base
{
	class Cell : public Entity
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
		virtual void init() override;
		virtual void render(app::gra::Window const & window, app::time::seconds const & dt) final override;

		void setColor(app::gra::Color const & color) { m_renderRect.setColor(color); };
		void moveTo(std::uint32_t const & r, std::uint32_t const & c);
		void moveTo(math::Vector2u const & gridPosition);
		void move(std::int32_t const & r, std::int32_t const & c);
		void move(math::Vector2i const & offset);

		constexpr app::math::Vector2u const & getGridPosition() const { return m_gridPosition; }
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
		void render(app::gra::Window const & window);
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		static math::Vector2f s_cellSizeFloat;
	private: // Private Member Variables
		gra::RenderRect m_renderRect;
		math::Vector2u m_gridPosition;
	};

	static_assert(std::is_destructible<Cell>::value, "Cell must be destructible");
	static_assert(std::is_move_assignable<Cell>::value, "Cell must be move assignable");
}
