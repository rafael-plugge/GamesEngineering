#pragma once

#include "math/Vector4.hpp"

namespace app::gra
{
	class RenderLine
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		RenderLine() = default;
		~RenderLine() = default;

		RenderLine(RenderLine const &) = default;
		RenderLine & operator=(RenderLine const &) = default;

		RenderLine(RenderLine &&) = default;
		RenderLine & operator=(RenderLine &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr math::Vector4<std::uint8_t> const & getColor() const { return m_color; }
		constexpr math::Vector2i const & getStart() const { return m_start; }
		constexpr math::Vector2i const & getEnd() const { return m_end; }

		RenderLine & setColor(math::Vector4<std::uint8_t> const & color) { m_color = color; return *this; }
		RenderLine & setColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255u) { return setColor({ r, g, b, a }); }
		RenderLine & setStart(math::Vector2i const & startPosition) { m_start = startPosition; return *this; }
		RenderLine & setEnd(math::Vector2i const & endPosition) { m_end = endPosition; return *this; }
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
		math::Vector4<std::uint8_t> m_color = { 0u, 0u, 0u, 255u };
		math::Vector2i m_start;
		math::Vector2i m_end;
	};

	static_assert(std::is_default_constructible<RenderLine>::value, "RenderLine must be default constructible");
	static_assert(std::is_destructible<RenderLine>::value, "RenderLine must be destructible");
	static_assert(std::is_copy_constructible<RenderLine>::value, "RenderLine must be copy constructible");
	static_assert(std::is_copy_assignable<RenderLine>::value, "RenderLine must be copy assignable");
	static_assert(std::is_move_constructible<RenderLine>::value, "RenderLine must be move constructible");
	static_assert(std::is_move_assignable<RenderLine>::value, "RenderLine must be move assignable");
}

