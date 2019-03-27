#pragma once

#include "math/Vector4.hpp"

namespace app::gra
{
	class Color : protected math::Vector4<std::uint8_t>
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using u8 = std::uint8_t;
		using Vector3u8 = math::Vector3<u8>;
		using Vector4u8 = math::Vector4<u8>;
	public: // Constructors/Destructor/Assignments
		Color();
		Color(u8 const & _r, u8 const & _g, u8 const & _b, u8 const & _a = 255u);
		Color(Vector3u8 rgb, u8 _a = 255u);
		Color(Vector4u8 colors);
		virtual ~Color() = default;

		Color(Color const & other);
		Color & operator=(Color const & other);

		Color(Color && other);
		Color & operator=(Color && other);

	public: // Public Static Functions
	public: // Public Member Functions
		std::uint8_t & r;
		std::uint8_t & g;
		std::uint8_t & b;
		std::uint8_t & a;
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

	static_assert(std::is_default_constructible<Color>::value, "Color must be default constructible");
	static_assert(std::is_destructible<Color>::value, "Color must be destructible");
	static_assert(std::is_copy_constructible<Color>::value, "Color must be copy constructible");
	static_assert(std::is_copy_assignable<Color>::value, "Color must be copy assignable");
	static_assert(std::is_move_constructible<Color>::value, "Color must be move constructible");
	static_assert(std::is_move_assignable<Color>::value, "Color must be move assignable");
}
