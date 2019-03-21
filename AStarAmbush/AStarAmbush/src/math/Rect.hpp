#pragma once

#include "Vector2.hpp"

namespace app::math
{
	template<typename _Types>
	class Rect
	{
	public: // Constructors/Destructor/Assignments
		Rect();
		Rect(_Types const & _x, _Types const & _y, _Types const & _w, _Types const & _h);
		Rect(Vector2<_Types> const & position, Vector2<_Types> const & size);
		
		~Rect() = default;

		Rect(Rect const &) = default;
		Rect & operator=(Rect const &) = default;
		Rect(Rect &&) = default;
		Rect & operator=(Rect &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		math::Vector2<_Types> halfSize() const { return math::Vector2<_Types>{ this->w, this->h } / static_cast<_Types>(2); }
		math::Vector2<_Types> center() const { return math::Vector2<_Types>{ this->x, this->y } + this->halfSize(); }

		operator std::string() const;
	public: // Public Static Variables
	public: // Public Member Variables
		_Types x, y, w, h;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		constexpr static _Types const zero = static_cast<_Types>(0u);
	private: // Private Member Variables
	};

	typedef Rect<std::double_t> Rectd;
	typedef Rect<std::float_t> Rectf;
	typedef Rect<std::int32_t> Recti;
	typedef Rect<std::uint32_t> Rectu;
}
