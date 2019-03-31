﻿#pragma once

namespace app::sin
{
	template<typename _Type, typename _Deleter = std::default_delete<_Type>>
	class Singleton
	{
		static_assert(std::is_default_constructible<_Type>::value, "_Type must be default constructible");
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Singleton() = delete;
		~Singleton() = delete;

		Singleton(Singleton const &) = delete;
		Singleton & operator=(Singleton const &) = delete;

		Singleton(Singleton &&) = delete;
		Singleton & operator=(Singleton &&) = delete;

	public: // Public Static Functions
		static _Type * const get();
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		static std::unique_ptr<_Type, _Deleter> s_instance;
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	template<typename _Type, typename _Deleter>
	std::unique_ptr<_Type, _Deleter> Singleton<_Type, _Deleter>::s_instance = Singleton<_Type, _Deleter>::s_instance
		? std::move(Singleton<_Type, _Deleter>::s_instance)
		: std::make_unique<_Type>();

	template<typename _Type, typename _Deleter>
	_Type * const Singleton<_Type, _Deleter>::get()
	{
		if (!s_instance) { s_instance = std::make_unique<_Type>(); }
		return s_instance.get();
	}
}
