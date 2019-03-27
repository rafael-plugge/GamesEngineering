#pragma once

#include "Color.hpp"

namespace app::gra
{
	class RenderRect
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		RenderRect() = default;
		~RenderRect() = default;

		RenderRect(RenderRect const &) = default;
		RenderRect & operator=(RenderRect const &) = default;

		RenderRect(RenderRect &&) = default;
		RenderRect & operator=(RenderRect &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr auto const & getPosition() const { return m_position; }
		constexpr auto const & getSize() const { return m_size; }
		constexpr auto const & getColor() const { return m_color; }

		RenderRect & setPosition(math::Vector2i const & position) { m_position = position; return *this; }
		RenderRect & setSize(math::Vector2i const & size) { m_size = size; return *this; }
		RenderRect & setColor(Color const & color) { m_color = color; return *this; }
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
		math::Vector2i m_position;
		math::Vector2i m_size;
		Color m_color;
	};

	static_assert(std::is_default_constructible<RenderRect>::value, "RenderRect must be default constructible");
	static_assert(std::is_destructible<RenderRect>::value, "RenderRect must be destructible");
	static_assert(std::is_copy_constructible<RenderRect>::value, "RenderRect must be copy constructible");
	static_assert(std::is_copy_assignable<RenderRect>::value, "RenderRect must be copy assignable");
	static_assert(std::is_move_constructible<RenderRect>::value, "RenderRect must be move constructible");
	static_assert(std::is_move_assignable<RenderRect>::value, "RenderRect must be move assignable");
}

