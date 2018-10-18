#ifndef _WINDOW_H
#define _WINDOW_H

#include "utilities/SdlDeleter.h"
#include "utilities/Keyhandler.h"
#include "utilities/MouseHandler.h"

namespace app::gra
{
	class Window
	{
	private: // Private type definitions
		typedef std::unique_ptr<SDL_Window, app::util::SdlDeleter> UPtrWindow;
		typedef std::unique_ptr<SDL_Renderer, app::util::SdlDeleter> UPtrRenderer;

	public: // Constructors/Destructor/Assignments
		Window(app::util::KeyHandler<app::KeyCode> & keyHandler, app::util::MouseHandler & mouseHandler, std::string const & title, std::size_t const & width, std::size_t const & height);
		~Window();

	public: // Public Member Functions

		void pollEvents();
		void clear() const;
		void display() const;

		inline constexpr bool const & isOpen() { return m_open; }
		inline std::shared_ptr<SDL_Renderer> getRenderer() { return m_renderer; }
	public: // Public Member Variables
	protected: // Protected Member Functions
	protected: // Protected Member Variables
	private: // Private Member Functions
		bool init();
		bool initWindow();
		bool initRenderer(UPtrWindow const & uptrSdlWindow);

	private: // Private Static Variables
		static constexpr SDL_Color s_BG_COLOR = { 0u, 0u, 0u, 255u };
	private: // Private Member Variables
		app::util::KeyHandler<app::KeyCode> & m_keyhandler;
		app::util::MouseHandler & m_mousehandler;
		bool m_open;
		std::string m_title;
		std::size_t m_width;
		std::size_t m_height;
		UPtrWindow m_window;
		std::shared_ptr<SDL_Renderer> m_renderer;
	};

}

#endif // !_WINDOW_H
