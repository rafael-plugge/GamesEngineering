﻿#ifndef _WINDOW_H
#define _WINDOW_H

#include "input/Keyhandler.hpp"
#include "input/Mousehandler.hpp"
#include "deleters/SdlDeleter.hpp"
#include "graphics/WindowParameters.hpp"
#include "graphics/RenderRect.hpp"
#include "graphics/View.hpp"

namespace app::gra
{
	class Window
	{
	public: // Constructors/Destructor/Assignments
		Window(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler, app::inp::ControllerHandler & controllerHandler, WindowParameters params);
		~Window();

	public: // Public Member Functions

		void setView(app::gra::View const & view);
		void resetView();
		void pollEvents();
		void clear() const;
		void render(app::gra::RenderRect const & rect) const;
		void render(std::unique_ptr<SDL_Texture> const & texture, SDL_Rect const & rect, std::optional<SDL_Rect> source = std::nullopt) const;
		void render(std::shared_ptr<SDL_Texture> texture, SDL_Rect const & rect, std::optional<SDL_Rect> source = std::nullopt) const;
		void display() const;

		inline constexpr auto const & isOpen() { return m_open; }
		inline constexpr auto const & getRenderer() { return m_renderer; }
		inline constexpr auto const & getWidth() { return m_width; }
		inline constexpr auto const & getHeight() { return m_height; }
	public: // Public Member Variables
	protected: // Protected Member Functions
	protected: // Protected Member Variables
	private: // Private Member Functions
		bool init();
		bool initWindow();
		bool initRenderer(app::del::UPtrWindow const & uptrSdlWindow);

	private: // Private Static Variables
		static constexpr SDL_Color s_BG_COLOR = { 0u, 0u, 0u, 255u };
	private: // Private Member Variables
		app::inp::KeyHandler & m_keyhandler;
		app::inp::MouseHandler & m_mousehandler;
		app::inp::ControllerHandler & m_controllerHandler;
		bool m_open;
		std::string m_title;
		std::size_t m_width;
		std::size_t m_height;
		View m_view;
		app::del::UPtrWindow m_window;
		app::del::UPtrRenderer m_renderer;
	};

}

#endif // !_WINDOW_H
