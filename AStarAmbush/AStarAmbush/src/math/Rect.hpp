#pragma once

#include "Vector2.hpp"

namespace app::math
{
	template<typename _Type>
	class Rect
	{
	public: // Constructors/Destructor/Assignments
		Rect();
		Rect(_Type const & _x, _Type const & _y, _Type const & _w, _Type const & _h);
		Rect(Vector2<_Type> const & position, Vector2<_Type> const & size);
		template<typename _Other> Rect(Rect<_Other> const & other)
			: x(static_cast<_Type>(other.x))
			, y(static_cast<_Type>(other.y))
			, w(static_cast<_Type>(other.w))
			, h(static_cast<_Type>(other.h))
		{}
		
		~Rect() = default;

		Rect(Rect const &) = default;
		Rect & operator=(Rect const &) = default;
		Rect(Rect &&) = default;
		Rect & operator=(Rect &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		math::Vector2<_Type> halfSize() const { return math::Vector2<_Type>{ this->w, this->h } / static_cast<_Type>(2); }
		math::Vector2<_Type> center() const { return math::Vector2<_Type>{ this->x, this->y } + this->halfSize(); }

		operator std::string() const;
	public: // Public Static Variables
	public: // Public Member Variables
		_Type x, y, w, h;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		constexpr static _Type const zero = static_cast<_Type>(0u);
	private: // Private Member Variables
	};

	typedef Rect<std::double_t> Rectd;
	typedef Rect<std::float_t> Rectf;
	typedef Rect<std::int32_t> Recti;
	typedef Rect<std::uint32_t> Rectu;
}
