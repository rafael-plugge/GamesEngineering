#ifndef _PLAYER_COMMAND_H
#define _PLAYER_COMMAND_H

#include "CmdPattern/Command.h"
#include "FSMPattern/State.h"

// components
#include "app/components/FiniteStateMachine.h"

namespace app::cmd
{
	template<typename T>
	class PlayerCommand : public Command
	{
	public: // Constructors/Destructor/Assignments
		PlayerCommand(PlayerCommand const &) = default;
		PlayerCommand(PlayerCommand &&) = default;

		~PlayerCommand() = default;

		PlayerCommand & operator=(PlayerCommand const &) = default;
		PlayerCommand & operator=(PlayerCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() override;
		virtual void undo() override;
		virtual void redo() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
		PlayerCommand(app::Registry & registry, app::Entity const entity);
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Registry & m_registry;
		app::Entity const m_entity;
		std::shared_ptr<fsm::State> m_state;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	#pragma region IMPLEMENTATION

	template<typename T>
	app::cmd::PlayerCommand<T>::PlayerCommand(app::Registry & registry, app::Entity const entity)
		: Command()
		, m_registry(registry)
		, m_entity(entity)
	{
	}

	template<typename T>
	void app::cmd::PlayerCommand<T>::execute()
	{
		assert(m_registry.valid(m_entity));
		auto & finiteStateMachine = m_registry.get<comp::FiniteStateMachine>(m_entity);
		finiteStateMachine.stateMachine->setState(m_state);
	}

	template<typename T>
	void app::cmd::PlayerCommand<T>::undo()
	{
	}

	template<typename T>
	void app::cmd::PlayerCommand<T>::redo()
	{
	}

	#pragma endregion

}

#endif // !_PLAYER_COMMAND_H
