#pragma once

#include "graphics/Window.hpp"
#include "managers/EntityManager.hpp"

namespace app
{
	class Game
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Game();
		~Game();

		Game(Game const &) = delete;
		Game & operator=(Game const &) = delete;

		Game(Game &&) = delete;
		Game & operator=(Game &&) = delete;

	public: // Public Static Functions
	public: // Public Member Functions
		constexpr bool isRunning() { return m_running && m_window.isOpen(); }
		bool init();
		void pollEvents();
		void update(app::time::seconds const & dt);
		void render(app::time::seconds const & dt);
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
		bool m_running;
		app::inp::KeyHandler m_keyHandler;
		app::inp::MouseHandler m_mouseHandler;
		app::inp::ControllerHandler m_controllerHandler;
		app::gra::Window m_window;
		app::ent::Grid m_grid;
		std::uint32_t m_fps;
	};

	static_assert(std::is_default_constructible<Game>::value, "Game must be default constructible");
	static_assert(std::is_destructible<Game>::value, "Game must be destructible");
}

