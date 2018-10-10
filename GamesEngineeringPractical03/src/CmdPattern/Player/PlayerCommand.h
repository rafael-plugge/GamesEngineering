#ifndef _PLAYER_COMMAND_H
#define _PLAYER_COMMAND_H

#include "CmdPattern/Command.h"
#include "FSMPattern/State.h"

// components
#include "app/components/FiniteStateMachine.h"

namespace app::cmd
{
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
		template<typename T> T & getComp();
		template<typename T> T const & getComp() const;
		template<typename T> T & getCompTag();
		template<typename T> T const & getCompTag() const;
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

	#pragma region Template Implementation

	template<typename T>
	inline T & app::cmd::PlayerCommand::getComp()
	{
		assert(m_registry.valid(m_entity));
		return m_registry.get<T>(m_entity);
	}

	template<typename T>
	inline T const & app::cmd::PlayerCommand::getComp() const
	{
		assert(m_registry.valid(m_entity));
		return m_registry.get<T>(m_entity);
	}

	template<typename T>
	inline T & app::cmd::PlayerCommand::getCompTag()
	{
		assert(m_registry.valid(m_entity));
		return m_registry.get<T>();
	}

	template<typename T>
	inline T const & app::cmd::PlayerCommand::getCompTag() const
	{
		assert(m_registry.valid(m_entity));
		return m_registry.get<T>();
	}

	#pragma endregion


}

#endif // !_PLAYER_COMMAND_H
