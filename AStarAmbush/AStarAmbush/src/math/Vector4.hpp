#pragma once

#include "Vector.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"

namespace app::math
{
	template<typename _Type>
	class Vector4 : public Vector<4, _Type>
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using BaseVector = Vector<4, _Type>;
	public: // Constructors/Destructor/Assignments
		Vector4()
			: BaseVector()
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
			, w(BaseVector::m_values.at(3))
		{}
		Vector4(_Type const & _x, _Type const & _y, _Type const & _z, _Type const & _w)
			: BaseVector({ _x, _y, _z, _w })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
			, w(BaseVector::m_values.at(3))
		{}
		Vector4(Vector3<_Type> const & v, _Type const _w)
			: BaseVector({ v.x, v.y, v.z, _w })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
			, w(BaseVector::m_values.at(3))
		{}
		Vector4(Vector2<_Type> const & leftV, Vector2<_Type> const & rightV)
			: BaseVector({ leftV.x, leftV.y, rightV.x, rightV.y })
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
			, w(BaseVector::m_values.at(3))
		{}

		~Vector4() = default;

		Vector4(Vector4 const & other)
			: BaseVector(other)
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
			, w(BaseVector::m_values.at(3))
		{}
		Vector4 & operator=(Vector4 const & other)
		{
			BaseVector::operator=(other);
			return *this;
		}

		Vector4(Vector4 && other)
			: BaseVector(other)
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
			, w(BaseVector::m_values.at(3))
		{}
		Vector4 & operator=(Vector4 && other)
		{
			BaseVector::operator=(other);
			return *this;
		}

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		_Type & x;
		_Type & y;
		_Type & z;
		_Type & w;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	using Vector4d = Vector4<std::double_t>;
	using Vector4f = Vector4<std::float_t>;
	using Vector4i = Vector4<std::int32_t>;
	using Vector4u = Vector4<std::uint32_t>;
}

