#include "stdafx.hpp"
#include "Color.hpp"

app::gra::Color::Color()
	: Vector4u8()
	, r(Vector4u8::x)
	, g(Vector4u8::y)
	, b(Vector4u8::z)
	, a(Vector4u8::w)
{
}

app::gra::Color::Color(u8 const & _r, u8 const & _g, u8 const & _b, u8 const & _a)
	: Vector4u8(_r, _g, _b, _a)
	, r(Vector4u8::x)
	, g(Vector4u8::y)
	, b(Vector4u8::z)
	, a(Vector4u8::w)
{
}

app::gra::Color::Color(Vector3u8 rgb, u8 _a)
	: Vector4u8(rgb, _a)
	, r(Vector4u8::x)
	, g(Vector4u8::y)
	, b(Vector4u8::z)
	, a(Vector4u8::w)
{
}

app::gra::Color::Color(Vector4u8 colors)
	: Vector4u8(std::move(colors))
	, r(Vector4u8::x)
	, g(Vector4u8::y)
	, b(Vector4u8::z)
	, a(Vector4u8::w)
{
}

app::gra::Color::Color(Color const & other)
	: Vector4u8(other)
	, r(Vector4u8::x)
	, g(Vector4u8::y)
	, b(Vector4u8::z)
	, a(Vector4u8::w)
{
}

app::gra::Color & app::gra::Color::operator=(Color const & other)
{
	Vector4u8::operator=(other);
	return *this;
}

app::gra::Color::Color(Color && other)
	: Vector4u8(std::move(other))
	, r(Vector4u8::x)
	, g(Vector4u8::y)
	, b(Vector4u8::z)
	, a(Vector4u8::w)
{
}

app::gra::Color & app::gra::Color::operator=(Color && other)
{
	Vector4u8::operator=(std::move(other));
	return *this;
}
