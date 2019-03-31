#pragma once

#include "Singleton.hpp"
#include "search/ProcessQueue.hpp"

namespace app::sin
{
	class ProcessQueue : public Singleton<app::sea::ProcessQueue>
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		ProcessQueue() = delete;
		~ProcessQueue() = delete;
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}
