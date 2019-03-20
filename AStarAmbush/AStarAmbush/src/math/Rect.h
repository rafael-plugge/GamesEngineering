#ifndef _MATH_RECT_H
#define _MATH_RECT_H

#include "Vector2.h"

namespace app::math
{
	template<typename T>
	class Rect
	{
	public: // Constructors/Destructor/Assignments
		Rect();
		Rect(T const & _x, T const & _y, T const & _w, T const & _h);
		Rect(Vector2<T> const & position, Vector2<T> const & size);
		
		~Rect() = default;

		Rect(Rect const &) = default;
		Rect & operator=(Rect const &) = default;
		Rect(Rect &&) = default;
		Rect & operator=(Rect &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		math::Vector2<T> halfSize() const { return math::Vector2<T>{ this->w, this->h } / static_cast<T>(2); }
		math::Vector2<T> center() const { return math::Vector2<T>{ this->x, this->y } + this->halfSize(); }

		operator std::string() const;
	public: // Public Static Variables
	public: // Public Member Variables
		T x, y, w, h;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		constexpr static T const zero = static_cast<T>(0u);
	private: // Private Member Variables
	};

	typedef Rect<std::double_t> Rectd;
	typedef Rect<std::float_t> Rectf;
	typedef Rect<std::int32_t> Recti;
	typedef Rect<std::uint32_t> Rectu;
}

template<typename T>
app::math::Rect<T>::Rect()
	: x(zero)
	, y(zero)
	, w(zero)
	, h(zero)
{
}

template<typename T>
app::math::Rect<T>::Rect(T const & _x, T const & _y, T const & _w, T const & _h)
	: x(_x)
	, y(_y)
	, w(_w)
	, h(_h)
{
}

template<typename T>
app::math::Rect<T>::Rect(math::Vector2<T> const & position, math::Vector2<T> const & size)
	: x(position.x)
	, y(position.y)
	, w(size.x)
	, h(size.y)
{
}

template<typename T>
app::math::Rect<T>::operator std::string() const
{
	return std::to_string(this->x) + ", " + std::to_string(this->y) + " : " + std::to_string(this->w) + ", " + std::to_string(this->h);
}

#endif // !_MATH_RECT_H
