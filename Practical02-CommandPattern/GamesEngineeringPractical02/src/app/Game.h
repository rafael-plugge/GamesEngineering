#ifndef _GAME_H
#define _GAME_H

#include "Window.h"

namespace app
{
	class Game
	{
	public: // Constructors/Destructor/Assignments
		Game();
		~Game();

	public: // Public Member Functions
		int run();

	public: // Public Member Variables
	protected: // Protected Member Functions
	protected: // Protected Member Variables
	private: // Private Member Functions
		bool init();
		void update(app::seconds const & dt);
		void render();

	private: // Private Static Variables
		static constexpr app::seconds s_updateStep =
			std::chrono::duration_cast<app::seconds>(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	private: // Private Member Variables
		app::Window m_window;
	};

}

#endif // !_GAME_H
