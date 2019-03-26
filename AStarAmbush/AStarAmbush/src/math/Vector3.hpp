#pragma once

#include "Vector.hpp"
#include "Vector2.hpp"

namespace app::math
{
	template<typename _Type>
	class Vector3 : public Vector<3, _Type>
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using BaseVector = Vector<3, _Type>;
	public: // Constructors/Destructor/Assignments
		Vector3()
			: BaseVector()
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		Vector3(_Type const & _x, _Type const & _y, _Type const & _z)
			: BaseVector({ _x, _y, _z })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		Vector3(Vector2<_Type> const & v, _Type const & _z)
			: BaseVector({ v.x, v.y, _z })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		template<typename _Other> Vector3(_Other const & _x, _Other const & _y, _Other const & _z)
			: BaseVector(std::array<_Other, 3>{ _x, _y, _z })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		explicit Vector3(BaseVector const & v)
			: BaseVector(v)
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		Vector3 & operator=(BaseVector const & v)
		{
			BaseVector::operator=(v);
			return *this;
		}

		~Vector3() = default;

		Vector3(Vector3 const & other)
			: BaseVector(other)
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		Vector3 & operator=(Vector3 const & other)
		{
			BaseVector::operator=(other);
			return *this;
		}
		template<typename _Other> Vector3 & operator=(Vector3<_Other> const & other)
		{
			BaseVector::operator=(other);
			return *this;
		}

		Vector3(Vector3 && other)
			: BaseVector(std::move(other))
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		Vector3 & operator=(Vector3 && other)
		{
			BaseVector::operator=(other);
			return *this;
		}
		template<typename _Other> Vector3 & operator=(Vector3<_Other> && other)
		{
			BaseVector::operator=(other);
			return *this;
		}

	public: // Public Static Functions

		#pragma region Plus Operators

		friend Vector3<_Type> operator+(Vector3<_Type> leftV, Vector3<_Type> const & rightV)
		{
			leftV += rightV;
			return std::move(leftV);
		}
		friend Vector3<_Type> operator+(Vector3<_Type> v, _Type const & t)
		{
			v += t;
			return std::move(v);
		}
		friend Vector3<_Type> operator+(_Type const & t, Vector3<_Type> v)
		{
			v = BaseVector::operator+(v, t);
			return std::move(v);
		}

		#pragma endregion

		#pragma region Minus Operators

		friend Vector3<_Type> operator-(Vector3<_Type> leftV, Vector3<_Type> const & rightV)
		{
			leftV -= rightV;
			return std::move(leftV);
		}
		friend Vector3<_Type> operator-(Vector3<_Type> v, _Type const & t)
		{
			v -= t;
			return std::move(v);
		}
		friend Vector3<_Type> operator-(_Type const & t, Vector3<_Type> v)
		{
			v = BaseVector::operator-(t, v);
			return std::move(v);
		}

		#pragma endregion

		#pragma region Multiplication Operators

		friend Vector3<_Type> operator*(Vector3<_Type> leftV, Vector3<_Type> const & rightV)
		{
			leftV *= rightV;
			return std::move(leftV);
		}
		friend Vector3<_Type> operator*(Vector3<_Type> v, _Type const & t)
		{
			v *= t;
			return std::move(v);
		}
		friend Vector3<_Type> operator*(_Type const & t, Vector3<_Type> v)
		{
			v = BaseVector::operator*(t, v);
			return std::move(v);
		}

		#pragma endregion

		#pragma region Division Operators

		friend Vector3<_Type> operator/(Vector3<_Type> leftV, Vector3<_Type> const & rightV)
		{
			leftV /= rightV;
			return std::move(leftV);
		}
		friend Vector3<_Type> operator/(Vector3<_Type> v, _Type const & t)
		{
			v /= t;
			return std::move(v);
		}
		friend Vector3<_Type> operator/(_Type const & t, Vector3<_Type> v)
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
		_Type & z;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	using Vector3d = Vector3<std::double_t>;
	using Vector3f = Vector3<std::float_t>;
	using Vector3i = Vector3<std::int32_t>;
	using Vector3u = Vector3<std::uint32_t>;
}

