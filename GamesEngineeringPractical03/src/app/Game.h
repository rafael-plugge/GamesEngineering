#ifndef _GAME_H
#define _GAME_H

#include "Window.h"
#include "app/system/BaseSystem.h"

namespace app
{
	class Game
	{
	public: // Constructors/Destructor/Assignments
		Game();
		Game(Game const &) = default;
		Game(Game &&) = default;
		~Game();
		Game & operator=(Game const &) = default;
		Game & operator=(Game &&) = default;
	public: // Public Static Functions
	public: // Public Member Functions
		int run();
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		bool init();
		bool createComponentDependencies();
		bool createSystems();
		bool createEntities();
		void update(app::seconds const & dt);
		void render(app::seconds const & dt);
	private: // Private Static Variables
	private: // Private Member Variables
		entt::DefaultRegistry m_registry;
		app::util::KeyHandler<SDL_Keycode> m_keyhandler;
		app::util::MouseHandler m_mousehandler;
		app::Window m_window;
		std::array<std::unique_ptr<sys::BaseSystem>, 2> m_updateSystems;
		std::array<std::unique_ptr<sys::BaseSystem>, 2> m_renderSystems;
	};

}

#endif // !_GAME_H
