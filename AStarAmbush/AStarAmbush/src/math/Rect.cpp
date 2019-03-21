﻿#include "stdafx.hpp"
#include "Rect.hpp"

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
app::math::Rect<T>::Rect(Vector2<T> const & position, Vector2<T> const & size)
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

template class app::math::Rect<std::double_t>;
template class app::math::Rect<std::float_t>;
template class app::math::Rect<std::int32_t>;
template class app::math::Rect<std::uint32_t>;
