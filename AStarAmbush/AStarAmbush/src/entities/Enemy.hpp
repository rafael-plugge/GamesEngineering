#pragma once

#include "base/Cell.hpp"
#include "entities/Player.hpp"
#include "search/ProcessQueue.hpp"

namespace app::ent
{
	class Enemy : public base::Cell
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Enemy();
		virtual ~Enemy() = default;

		Enemy(Enemy const & other);
		Enemy & operator=(Enemy const & other);

		Enemy(Enemy && other);
		Enemy & operator=(Enemy && other);

	public: // Public Static Functions
		static void setTarget(app::ent::Player const & target);
	public: // Public Member Functions
		virtual void init() final override;
		void init(math::Vector2u const & startingPosition);
		virtual void update(app::time::seconds const & dt) final override;

	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
		Player const & getTarget();
	private: // Private Member Functions
		void searchPlayer();
	private: // Private Static Variables
		static std::optional<app::ent::Player const * const> s_target;
	private: // Private Member Variables
		inp::KeyHandler const * const m_keyHandler;
		sea::ProcessQueue * const m_processQueue;
		std::atomic_bool m_seekTarget;
		std::function<void()> const m_searchTask;
	};

	static_assert(std::is_default_constructible<Enemy>::value, "Enemy must be default constructible");
	static_assert(std::is_destructible<Enemy>::value, "Enemy must be destructible");
	static_assert(std::is_copy_constructible<Enemy>::value, "Enemy must be copy constructible");
	static_assert(std::is_copy_assignable<Enemy>::value, "Enemy must be copy assignable");
	static_assert(std::is_move_constructible<Enemy>::value, "Enemy must be move constructible");
	static_assert(std::is_move_assignable<Enemy>::value, "Enemy must be move assignable");
}
