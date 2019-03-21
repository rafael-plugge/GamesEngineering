#include "stdafx.hpp"
#include "Rect.hpp"

template<typename _Types>
app::math::Rect<_Types>::Rect()
	: x(zero)
	, y(zero)
	, w(zero)
	, h(zero)
{
}

template<typename _Types>
app::math::Rect<_Types>::Rect(_Types const & _x, _Types const & _y, _Types const & _w, _Types const & _h)
	: x(_x)
	, y(_y)
	, w(_w)
	, h(_h)
{
}

template<typename _Types>
app::math::Rect<_Types>::Rect(Vector2<_Types> const & position, Vector2<_Types> const & size)
	: x(position.x)
	, y(position.y)
	, w(size.x)
	, h(size.y)
{
}

template<typename _Types>
app::math::Rect<_Types>::operator std::string() const
{
	return std::to_string(this->x) + ", " + std::to_string(this->y) + " : " + std::to_string(this->w) + ", " + std::to_string(this->h);
}

template class app::math::Rect<std::double_t>;
template class app::math::Rect<std::float_t>;
template class app::math::Rect<std::int32_t>;
template class app::math::Rect<std::uint32_t>;
