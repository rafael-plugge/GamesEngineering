#ifndef _PLAYER_RUNNING_STATE_FACTORY_H
#define _PLAYER_RUNNING_STATE_FACTORY_H

#include "StateFactory.h"

namespace app::fact
{
	class PlayerRunningStateFactory : public StateFactory
	{
	public: // Constructors/Destructor/Assignments
		PlayerRunningStateFactory() = default;
		PlayerRunningStateFactory(PlayerRunningStateFactory const &) = default;
		PlayerRunningStateFactory(PlayerRunningStateFactory &&) = default;

		~PlayerRunningStateFactory() = default;

		PlayerRunningStateFactory & operator=(PlayerRunningStateFactory const &) = default;
		PlayerRunningStateFactory & operator=(PlayerRunningStateFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::shared_ptr<app::fsm::State> create() const override;
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

#endif // !_PLAYER_RUNNING_STATE_FACTORY_H
