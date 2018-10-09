#ifndef _STATE_H
#define _STATE_H

namespace app::fsm
{
	class State
	{
	public: // Constructors/Destructor/Assignments
		State(State const &) = default;
		State(State &&) = default;

		~State() = default;

		State & operator=(State const &) = default;
		State & operator=(State &&) = default;

	public: // Public Static Functions
		static std::shared_ptr<State> ptr() { return s_singlePtr; }
	public: // Public Member Functions
		virtual void update(app::seconds const & dt) {}
		virtual void setState(std::shared_ptr<State> newState) { s_singlePtr = newState; }
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
		State() = default;
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		static std::shared_ptr<State> s_singlePtr;
	private: // Private Member Variables

	};
}

#endif // !_STATE_H
