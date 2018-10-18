#ifndef _GRAPHICS_GAME_H
#define _GRAPHICS_GAME_H

#include "utilities/Keyhandler.h"
#include "utilities/MouseHandler.h"
#include "utilities/Time.h"
#include "graphics/Window.h"

namespace app::gra
{
	class Game
	{
	public: // Constructors/Destructor/Assignments
		Game();
		Game(Game const &) = delete;
		Game(Game &&) = delete;

		~Game();

		Game & operator=(Game const &) = delete;
		Game & operator=(Game &&) = delete;

	public: // Public Static Functions
	public: // Public Member Functions
		int run();
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
		bool init();
		bool initEntities();
		bool initSystems();
		void pollEvents();
		void update(app::time::nanoseconds const & dt);
		void render(app::time::nanoseconds const & dt);
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		bool m_gameLoop;
		app::util::KeyHandler<app::KeyCode> m_keyHandler;
		app::util::MouseHandler m_mouseHandler;
		app::gra::Window m_window;

		sys::AiSystem m_aiSystem;
		//app::sys::ControlSystem m_controlSystem;
		//app::sys::RenderSystem m_renderSystem;
	};
}

#endif // !_GRAPHICS_GAME_H
