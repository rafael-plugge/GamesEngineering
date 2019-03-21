#pragma once

#include "entities/base/Drawable.hpp"

namespace app::ent
{
	class Grid : public base::Drawable
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Grid();
		~Grid() = default;

		Grid(Grid const &) = default;
		Grid & operator=(Grid const &) = default;

		Grid(Grid &&) = default;
		Grid & operator=(Grid &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::seconds const & dt) final override;
		virtual void render(app::gra::Window const & window, app::time::seconds const & dt) final override;
	public: // Public Static Variables
		constexpr static std::size_t const GRID_WIDTH = 100u;
		constexpr static std::size_t const GRID_HEIGHT = 100u;
		constexpr static std::size_t const GRID_SIZE = GRID_WIDTH * GRID_HEIGHT;
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		std::array<std::array<std::int32_t, GRID_HEIGHT>, GRID_WIDTH> m_grid;
	};

	static_assert(std::is_default_constructible<Grid>::value, "Grid must be default constructible");
	static_assert(std::is_destructible<Grid>::value, "Grid must be destructible");
	static_assert(std::is_copy_constructible<Grid>::value, "Grid must be copy constructible");
	static_assert(std::is_copy_assignable<Grid>::value, "Grid must be copy assignable");
	static_assert(std::is_move_constructible<Grid>::value, "Grid must be move constructible");
	static_assert(std::is_move_assignable<Grid>::value, "Grid must be move assignable");
}
