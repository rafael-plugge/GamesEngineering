﻿#pragma once

#include "base/Cell.hpp"
#include "graphics/RenderRect.hpp"
#include "input/Keyhandler.hpp"

namespace app::ent
{
	class Player : public base::Cell
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Player();
		virtual ~Player() = default;

		Player(Player const &) = default;
		Player & operator=(Player const & other);

		Player(Player &&) = default;
		Player & operator=(Player && other);

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const & dt) final override;
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
		inp::KeyHandler const * const m_keyHandler;
	};

	static_assert(std::is_default_constructible<Player>::value, "Player must be default constructible");
	static_assert(std::is_destructible<Player>::value, "Player must be destructible");
	static_assert(std::is_copy_constructible<Player>::value, "Player must be copy constructible");
	static_assert(std::is_copy_assignable<Player>::value, "Player must be copy assignable");
	static_assert(std::is_move_constructible<Player>::value, "Player must be move constructible");
	static_assert(std::is_move_assignable<Player>::value, "Player must be move assignable");
}