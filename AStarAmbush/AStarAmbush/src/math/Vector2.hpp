#pragma once

#include "Vector.hpp"

namespace app::math
{
	template<typename _Type>
	class Vector2 : public Vector<2, _Type>
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using BaseVector = Vector<2, _Type>;
	public: // Constructors/Destructor/Assignments
		Vector2()
			: BaseVector()
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
		{}
		Vector2(_Type const & _x, _Type const & _y)
			: BaseVector({ _x, _y })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
		{}
		template<typename _Other> Vector2(_Other const & _x, _Other const & _y)
			: BaseVector(std::array<_Other, 2>{ _x, _y })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
		{}
		explicit Vector2(BaseVector const & v)
			: BaseVector(v)
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
		{}
		Vector2 & operator=(BaseVector const & v)
		{
			BaseVector::operator=(v);
			return *this;
		}

		~Vector2() = default;

		Vector2(Vector2 const & other)
			: BaseVector(other)
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
		{}
		Vector2 & operator=(Vector2 const & other)
		{
			BaseVector::operator=(other);
			return *this;
		}
		template<typename _Other> Vector2 & operator=(Vector2<_Other> const & other)
		{
			BaseVector::operator=(other);
			return *this;
		}

		Vector2(Vector2 && other)
			: BaseVector(std::move(other))
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
		{}
		Vector2 & operator=(Vector2 && other)
		{
			BaseVector::operator=(other);
			return *this;
		}
		template<typename _Other> Vector2 & operator=(Vector2<_Other> && other)
		{
			BaseVector::operator=(other);
			return *this;
		}

	public: // Public Static Functions

		#pragma region Plus Operators

		friend Vector2<_Type> operator+(Vector2<_Type> leftV, Vector2<_Type> const & rightV)
		{
			leftV += rightV;
			return std::move(leftV);
		}
		friend Vector2<_Type> operator+(Vector2<_Type> v, _Type const & t)
		{
			v += t;
			return std::move(v);
		}
		friend Vector2<_Type> operator+(_Type const & t, Vector2<_Type> v)
		{
			v = BaseVector::operator+(v, t);
			return std::move(v);
		}

		#pragma endregion

		#pragma region Minus Operators

		friend Vector2<_Type> operator-(Vector2<_Type> leftV, Vector2<_Type> const & rightV)
		{
			leftV -= rightV;
			return std::move(leftV);
		}
		friend Vector2<_Type> operator-(Vector2<_Type> v, _Type const & t)
		{
			v -= t;
			return std::move(v);
		}
		friend Vector2<_Type> operator-(_Type const & t, Vector2<_Type> v)
		{
			v = BaseVector::operator-(t, v);
			return std::move(v);
		}

		#pragma endregion

		#pragma region Multiplication Operators

		friend Vector2<_Type> operator*(Vector2<_Type> leftV, Vector2<_Type> const & rightV)
		{
			leftV *= rightV;
			return std::move(leftV);
		}
		friend Vector2<_Type> operator*(Vector2<_Type> v, _Type const & t)
		{
			v *= t;
			return std::move(v);
		}
		friend Vector2<_Type> operator*(_Type const & t, Vector2<_Type> v)
		{
			v = BaseVector::operator*(t, v);
			return std::move(v);
		}

		#pragma endregion

		#pragma region Division Operators

		friend Vector2<_Type> operator/(Vector2<_Type> leftV, Vector2<_Type> const & rightV)
		{
			leftV /= rightV;
			return std::move(leftV);
		}
		friend Vector2<_Type> operator/(Vector2<_Type> v, _Type const & t)
		{
			v /= t;
			return std::move(v);
		}
		friend Vector2<_Type> operator/(_Type const & t, Vector2<_Type> v)
		{
			v = BaseVector::operator/(t, v);
			return std::move(v);
		}

		#pragma endregion

	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		_Type & x;
		_Type & y;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	using Vector2d = Vector2<std::double_t>;
	using Vector2f = Vector2<std::float_t>;
	using Vector2i = Vector2<std::int32_t>;
	using Vector2u = Vector2<std::uint32_t>;
}
