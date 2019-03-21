#pragma once

#include "Math.hpp"
#include "Vector2.hpp"

namespace app::math
{
	template<typename _Types> constexpr math::Vector2<_Types> rotate(math::Vector2<_Types> const & v, _Types angle) { return rotateRad(v, math::toRadians(angle)); }
	template<typename _Types> constexpr math::Vector2<_Types> rotateRad(math::Vector2<_Types> const & v, _Types rad)
	{
		const auto cosine = static_cast<_Types>(std::cos(rad));
		const auto sine = static_cast<_Types>(std::sin(rad));
		return math::Vector2<_Types> {
			v.x * cosine - v.y * sine,
				v.x * sine + v.y * cosine
		};
		return rotateAroundRad(v, rad, math::Vector2<_Types>{});
	}
	template<typename _Types> constexpr math::Vector2<_Types> rotateAround(math::Vector2<_Types> const & v, _Types angle, math::Vector2<_Types> const & point) { return rotateAroundRad(v, math::toRadians(angle), point); }
	template<typename _Types> constexpr math::Vector2<_Types> rotateAroundRad(math::Vector2<_Types> const & v, _Types rad, math::Vector2<_Types> const & point)
	{
		const auto cosine = static_cast<_Types>(std::cos(rad));
		const auto sine = static_cast<_Types>(std::sin(rad));
		return math::Vector2<_Types> {
			((v.x - point.x) * cosine) - ((point.y - v.y) * sine) + point.x,
				((point.y - v.y) * cosine) - ((v.x - point.x) * sine) + point.y
		};
	}
	template<typename _Types> constexpr math::Vector2<_Types> toVectorRad(_Types const & rad) { return math::Vector2<_Types>{ std::cos(rad), std::sin(rad) }; }
	template<typename _Types> constexpr math::Vector2<_Types> toVector(_Types const & deg) { return toVectorRad(toRadians(deg)); }
	template<typename _Types> constexpr _Types angleBetween(Vector2<_Types> const & left, Vector2<_Types> const & right)
	{
		return static_cast<_Types>(math::toDegrees(std::atan2(Vector2<_Types>::det(left, right), Vector2<_Types>::dot(left, right))));
	}
}
