#pragma once

#if !defined(_USE_STDAFX_HPP) && !defined(_USE_STDAFX_H)

#include <type_traits>
#include <random>

#endif // !_USE_STDAFX_HPP && !_USE_STDAFX_H

namespace app::util
{
	template<typename _Type>
	class Random
	{
		static_assert(std::is_default_constructible<_Type>::value, "_Type must be default constructible");
		static_assert(std::is_destructible<_Type>::value, "_Type must be destructible");
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using UniformDistribution = std::conditional_t<
			  std::is_integral<_Type>::value
			, std::uniform_int_distribution<_Type>
			, std::uniform_real_distribution<_Type>
		>;
	private: // Constructors/Destructor/Assignments
		Random() = default;
		~Random() = default;

		Random(Random const &) = default;
		Random & operator=(Random const &) = default;

		Random(Random &&) = default;
		Random & operator=(Random &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		static _Type gen(_Type const & start, _Type const & end);
		static _Type gen(_Type const & end);
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		static std::random_device s_randomDevice;
		static std::default_random_engine s_randomEngine;
		static UniformDistribution s_uniformDistribution;
	private: // Private Member Variables
	};
	using RandomInt = Random<std::int32_t>;
	using RandomFloat = Random<std::float_t>;
	using RandomDouble = Random<std::double_t>;
}

template<typename _Type> std::random_device app::util::Random<_Type>::s_randomDevice = std::random_device();
template<typename _Type> std::default_random_engine app::util::Random<_Type>::s_randomEngine = std::default_random_engine(Random<_Type>::s_randomDevice());
template<typename _Type> typename app::util::Random<_Type>::UniformDistribution app::util::Random<_Type>::s_uniformDistribution = app::util::Random<_Type>::UniformDistribution();

template<typename _Type>
inline _Type app::util::Random<_Type>::gen(_Type const & start, _Type const & end)
{
	if (s_uniformDistribution.min() != start || s_uniformDistribution.max() != end)
		s_uniformDistribution = UniformDistribution(start, end);
	return s_uniformDistribution(s_randomEngine);
}

template<typename _Type>
inline _Type app::util::Random<_Type>::gen(_Type const & end)
{
	return Random<_Type>::gen(static_cast<_Type>(0u), end);
}
