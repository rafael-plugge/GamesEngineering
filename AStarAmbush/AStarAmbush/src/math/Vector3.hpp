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

		Vector3(Vector3 && other)
			: BaseVector(other)
			, x(BaseVector::m_values.at(0))
			, y(BaseVector::m_values.at(1))
			, z(BaseVector::m_values.at(2))
		{}
		Vector3 & operator=(Vector3 && other)
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

