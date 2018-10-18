#ifndef _AI_SYSTEM_H
#define _AI_SYSTEM_H

#include "system/BaseSystem.h"

namespace app::sys
{
	class AiSystem : public app::sys::BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		AiSystem();
		AiSystem(AiSystem const &) = default;
		AiSystem(AiSystem &&) = default;

		~AiSystem() = default;

		AiSystem & operator=(AiSystem const &) = default;
		AiSystem & operator=(AiSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::nanoseconds const & dt) override;
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

#endif // !_AI_SYSTEM_H
