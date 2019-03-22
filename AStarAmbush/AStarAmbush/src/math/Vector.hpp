#pragma once

#include <cinttypes>
#include <cmath>
#include <cassert>
#include <array>
#include <initializer_list>
#include <numeric>
#include <algorithm>

namespace app::math
{
	/// 
	/// @brief N dimensional vector class.
	/// @author Rafael Plugge
	/// 
	/// Handles all mathematics behind N dimensional vectors.
	/// 
	template<std::size_t _Size, typename _Type>
	class Vector
	{
	public: // Public Usings/Typedefs/Enums
		static_assert(_Size > 0u, "_Size template parameter must be greater than zero");
		static_assert(std::is_arithmetic<_Type>::value, "_Type must be a arithmetic type");
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Vector()
			: m_values()
		{}

		Vector(std::array<_Type, _Size> const & _values)
			: m_values(_values)
		{}

		Vector(std::array<_Type, _Size> && _values)
			: m_values(_values)
		{}

		template<typename _Other> Vector(std::array<_Other, _Size> const & _values)
			: m_values()
		{
			for (std::size_t i = 0; i < _Size; ++i)
				m_values.at(i) = static_cast<_Type>(_values.at(i));
		}

		template<typename _Other> Vector(Vector<_Size, _Other> const & v)
			: m_values()
		{
			for (std::size_t i = 0; i < _Size; ++i)
				m_values.at(i) = static_cast<_Type>(v.get(i));
		}

		~Vector() = default;

		Vector(Vector const & other)
			: m_values(other.m_values)
		{}
		Vector & operator=(Vector const & other)
		{
			for (std::size_t i = 0; i < _Size; ++i)
				m_values.at(i) = other.m_values.at(i);
			return *this;
		}
		template<typename _Other> Vector & operator=(Vector<_Size, _Other> const & other)
		{
			for (std::size_t i = 0; i < _Size; ++i)
				m_values.at(i) = static_cast<_Type>(other.get(i));
			return *this;
		}

		Vector(Vector && other)
			: m_values(other.m_values)
		{}
		Vector & operator=(Vector && other)
		{
			for (std::size_t i = 0; i < _Size; ++i)
				m_values.at(i) = std::move(other.m_values.at(i));
			return *this;
		}
		template<typename _Other> Vector & operator=(Vector<_Size, _Other> && other)
		{
			for (std::size_t i = 0; i < _Size; ++i)
				m_values.at(i) = std::move(static_cast<_Type>(other.m_values.at(i)));
			return *this;
		}

	public: // Public Static Functions
		static Vector<_Size, _Type> const unit(Vector<_Size, _Type> const & v)
		{
			auto const length = v.magnitude();
			assert(length != zero);
			return Vector<_Size, _Type>() /= length;
		}
		static _Type dot(Vector<_Size, _Type> const & left, Vector<_Size, _Type> const & right)
		{
			auto sum = zero;
			for (std::size_t i = 0; i < _Size; ++i)
				sum += left.m_values.at(i) * right.m_values.at(i);
			return std::move(sum);
		}
		static _Type det(Vector<_Size, _Type> const & left, Vector<_Size, _Type> const & right)
		{
			auto dif = zero;
			for (std::size_t i = 0; i < _Size; ++i)
				dif -= left.m_values.at(i) * right.m_values.at(i);
			return std::move(dif);
		}

		#pragma region Plus Operators

		friend Vector<_Size, _Type> operator+(Vector<_Size, _Type> leftV, Vector<_Size, _Type> const & rightV)
		{
			for (std::size_t i = 0; i < _Size; ++i)
				leftV.m_values.at(i) += rightV.m_values.at(i);
			return std::move(leftV);
		}
		friend Vector<_Size, _Type> operator+(Vector<_Size, _Type> v, _Type const & t)
		{
			for (_Type & val : v.m_values) { val += t; }
			return std::move(v);
		}
		friend Vector<_Size, _Type> operator+(_Type const & t, Vector<_Size, _Type> v)
		{
			for (_Type & val : v.m_values) { val += t; }
			return std::move(v);
		}

		#pragma endregion

		#pragma region Minus Operators

		friend Vector<_Size, _Type> operator-(Vector<_Size, _Type> leftV, Vector<_Size, _Type> const & rightV)
		{
			for (std::size_t i = 0; i < _Size; ++i)
				leftV.m_values.at(i) -= rightV.m_values.at(i);
			return std::move(leftV);
		}
		friend Vector<_Size, _Type> operator-(Vector<_Size, _Type> v, _Type const & t)
		{
			for (_Type & val : v.m_values) { val -= t; }
			return std::move(v);
		}
		friend Vector<_Size, _Type> operator-(_Type const & t, Vector<_Size, _Type> v)
		{
			for (_Type & val : v.m_values) { val -= t; }
			return std::move(v);
		}

		#pragma endregion
		
		#pragma region Multiplication Operators

		friend Vector<_Size, _Type> operator*(Vector<_Size, _Type> leftV, Vector<_Size, _Type> const & rightV)
		{
			for (std::size_t i = 0; i < _Size; ++i)
				leftV.m_values.at(i) *= rightV.m_values.at(i);
			return std::move(leftV);
		}
		friend Vector<_Size, _Type> operator*(Vector<_Size, _Type> v, _Type const & t)
		{
			for (_Type & val : v.m_values) { val *= t; }
			return std::move(v);
		}
		friend Vector<_Size, _Type> operator*(_Type const & t, Vector<_Size, _Type> v)
		{
			for (_Type & val : v.m_values) { val *= t; }
			return std::move(v);
		}

		#pragma endregion

		#pragma region Division Operators

		friend Vector<_Size, _Type> operator/(Vector<_Size, _Type> leftV, Vector<_Size, _Type> const & rightV)
		{
			for (std::size_t i = 0; i < _Size; ++i)
			{
				assert(rightV.m_values.at(i) != this->zero);
				leftV.m_values.at(i) /= rightV.m_values.at(i);
			}
			return std::move(leftV);
		}
		friend Vector<_Size, _Type> operator/(Vector<_Size, _Type> v, _Type const & t)
		{
			assert(t != zero);
			for (_Type & val : v.m_values) { val /= t; }
			return std::move(v);
		}
		friend Vector<_Size, _Type> operator/(_Type const & t, Vector<_Size, _Type> v)
		{
			for (_Type & val : v.m_values)
			{
				assert(val != zero);
				val = t / val;
			}
			return std::move(v);
		}

		#pragma endregion

		#pragma region Equality Operators

		friend constexpr bool operator==(Vector<_Size, _Type> const & leftV, Vector<_Size, _Type> const & rightV)
		{
			return std::equal(leftV.m_values.cbegin(), leftV.m_values.cend(), rightV.m_values.cbegin(), rightV.m_values.cend(),
				[](_Type const & left, _Type const & right) { return left == right; });
		}
		friend constexpr bool operator==(Vector<_Size, _Type> const & v, _Type const & t)
		{
			return std::equal(v.m_values.cbegin(), v.m_values.cend(), t);
		}
		friend constexpr bool operator==(_Type const & t, Vector<_Size, _Type> const & v)
		{
			return std::equal(v.m_values.cbegin(), v.m_values.cend(), t);
		}

		#pragma endregion

		#pragma region Inequality Operators

		friend constexpr bool operator!=(Vector<_Size, _Type> const & leftV, Vector<_Size, _Type> const & rightV)
		{
			return std::equal(leftV.m_values.cbegin(), leftV.m_values.cend(), rightV.m_values.cbegin(), rightV.m_values.cend(),
				[](_Type const & left, _Type const & right) { return left != right; });
		}
		friend constexpr bool operator!=(Vector<_Size, _Type> const & v, _Type const & t)
		{
			return !std::equal(v.m_values.cbegin(), v.m_values.cend(), t);
		}
		friend constexpr bool operator!=(_Type const & t, Vector<_Size, _Type> const & v)
		{
			return !std::equal(v.m_values.cbegin(), v.m_values.cend(), t);
		}

		#pragma endregion

		friend Vector<_Size, _Type> operator-(Vector<_Size, _Type> v)
		{
			for (_Type & val : v.m_values) { val = -val; }
			return std::move(v);
		}

	public: // Public Member Functions
		Vector & operator=(_Type const & t)
		{
			this->m_values.fill(t);
			return *this;
		}

		Vector & operator+=(Vector const & v)
		{
			for (std::size_t i = 0; i < _Size; ++i) { m_values.at(i) += v.m_values.at(i); }
			return *this;
		}
		Vector & operator+=(_Type const & t)
		{
			for (auto & val : m_values) { val += t; }
			return *this;
		}

		Vector & operator-=(Vector const & v)
		{
			for (std::size_t i = 0; i < _Size; ++i) { m_values.at(i) -= v.m_values.at(i); }
			return *this;
		}
		Vector & operator-=(_Type const & t)
		{
			for (auto & val : m_values) { val -= t; }
			return *this;
		}

		Vector & operator*=(Vector const & v)
		{
			for (std::size_t i = 0; i < _Size; ++i) { m_values.at(i) *= v.m_values.at(i); }
			return *this;
		}
		Vector & operator*=(_Type const & t)
		{
			for (_Type & val : m_values) { val *= t; }
			return *this;
		}

		Vector & operator/=(Vector const & v)
		{
			for (std::size_t i = 0; i < _Size; ++i)
			{
				assert(v.m_values.at(i) != zero);
				m_values.at(i) /= v.m_values.at(i);
			}
			return *this;
		}
		Vector & operator/=(_Type const & t)
		{
			assert(t != zero);
			for (_Type & val : m_values) { val /= t; }
			return *this;
		}

		constexpr bool operator<(Vector const & v) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), v.m_values.cbegin(), v.m_values.cend(),
				[](_Type const & left, _Type const & right) { return left < right; });
		}
		constexpr bool operator<(_Type const & t) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), t,
				[](_Type const & left, _Type const & right) { left < right; });
		}

		constexpr bool operator>(Vector const & v) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), v.m_values.cbegin(), v.m_values.cend(),
				[](_Type const & left, _Type const & right) { return left > right; });
		}
		constexpr bool operator>(_Type const & t) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), t,
				[](_Type const & left, _Type const & right) { left > right; });
		}

		constexpr bool operator<=(Vector const & v) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), v.m_values.cbegin(), v.m_values.cend(),
				[](_Type const & left, _Type const & right) { return left <= right; });
		}
		constexpr bool operator<=(_Type const & t) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), t,
				[](_Type const & left, _Type const & right) { left <= right; });
		}

		constexpr bool operator>=(Vector const & v) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), v.m_values.cbegin(), v.m_values.cend(),
				[](_Type const & left, _Type const & right) { return left >= right; });
		}
		constexpr bool operator>=(_Type const & t) const
		{
			return std::equal(m_values.cbegin(), m_values.cend(), t,
				[](_Type const & left, _Type const & right) { left >= right; });
		}

		_Type magnitudeSqr() const
		{
			auto sum = zero;
			for (std::size_t i = 0; i < _Size; ++i)
				sum += m_values.at(i) * m_values.at(i);
			return std::move(sum);
		}
		_Type magnitude() const
		{
			return static_cast<_Type>(std::sqrt(magnitudeSqr()));
		}
		Vector<_Size, _Type> & truncate(_Type const & max)
		{
			auto const & length = this->magnitude();
			if (length > max)
				((*this) /= length) * max;
			return *this;
		}
		Vector<_Size, _Type> & unit()
		{
			auto const length = this->magnitude();
			assert(length != zero);
			(*this) /= length;
			return *this;
		}
		Vector<_Size, _Type> unit() const
		{
			auto const length = this->magnitude();
			assert(length != zero);
			return (*this) / length;
		}
		_Type dot(Vector<_Size, _Type> const & other) const
		{
			return app::math::Vector<_Size, _Type>::dot(*this, other);
		}
		_Type det(Vector<_Size, _Type> const & other) const
		{
			return app::math::Vector<_Size, _Type>::det(*this, other);
		}

		operator std::string() const
		{
			auto msg = std::stringstream(std::ios::out) << "(";
			for (std::size_t i = 0; i < (_Size - 1); ++i)
				msg << std::to_string(m_values.at(i)) << ", ";
			msg << std::to_string(m_values.back()) << ")";
			return msg.str();
		}

		constexpr _Type const & get(std::size_t const & index) const
		{
			return m_values.at(index);
		}

		constexpr _Type & get(std::size_t const & index)
		{
			return m_values.at(index);
		}

	public: // Public Static Variables
		constexpr static _Type const zero = static_cast<_Type>(0u);
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::array<_Type, _Size> m_values;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}
