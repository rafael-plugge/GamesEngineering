#include "stdafx.hpp"
#include "Rect.hpp"

template<typename _Type>
app::math::Rect<_Type>::Rect()
	: x(zero)
	, y(zero)
	, w(zero)
	, h(zero)
{
}

template<typename _Type>
app::math::Rect<_Type>::Rect(_Type const & _x, _Type const & _y, _Type const & _w, _Type const & _h)
	: x(_x)
	, y(_y)
	, w(_w)
	, h(_h)
{
}

template<typename _Type>
app::math::Rect<_Type>::Rect(Vector2<_Type> const & position, Vector2<_Type> const & size)
	: x(position.x)
	, y(position.y)
	, w(size.x)
	, h(size.y)
{
}

template<typename _Type>
app::math::Rect<_Type>::operator std::string() const
{
	return std::to_string(this->x) + ", " + std::to_string(this->y) + " : " + std::to_string(this->w) + ", " + std::to_string(this->h);
}

template class app::math::Rect<std::double_t>;
template class app::math::Rect<std::float_t>;
template class app::math::Rect<std::int32_t>;
template class app::math::Rect<std::uint32_t>;
