#ifndef _NON_DELETER_H
#define _NON_DELETER_H

namespace app::util
{
	class NonDeleter
	{
	public: // Constructors/Destructor/Assignments
		NonDeleter() = default;
		NonDeleter(NonDeleter const &) = default;
		NonDeleter(NonDeleter &&) = default;

		~NonDeleter() = default;

		NonDeleter & operator=(NonDeleter const &) = default;
		NonDeleter & operator=(NonDeleter &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		//void operator()(app::fsm::PlayerStateMachine * playerStateMachine) const {}
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

#endif // !_NON_DELETER_H
