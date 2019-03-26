#pragma once

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
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Window();
		Window(WindowParameters params);
		Window(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler, app::inp::ControllerHandler & controllerHandler, WindowParameters params);
		~Window();

		Window(Window const &) = default;
		Window & operator=(Window const &) = default;

		Window(Window &&) = default;
		Window & operator=(Window &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		bool init(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler, app::inp::ControllerHandler & controllerHandler, WindowParameters params);
		bool init(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler, WindowParameters params);
		bool init(app::inp::KeyHandler & keyHandler, WindowParameters params);
		bool init(WindowParameters params);
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
		inline constexpr auto const & getWidth() const { return m_width; }
		inline constexpr auto const & getHeight() const { return m_height; }

	public: // Public Static Variables
	public: // Public Member Variables
		static math::Vector2u getSize();
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		bool init();
		bool initWindow();
		bool initRenderer(app::del::UPtrWindow const & uptrSdlWindow);

	private: // Private Static Variables
		static constexpr SDL_Color s_BG_COLOR = { 0u, 0u, 0u, 255u };
		static std::optional<Window const * const> s_pWindow;
	private: // Private Member Variables
		std::optional<app::inp::KeyHandler * const> m_keyhandler;
		std::optional<app::inp::MouseHandler * const> m_mousehandler;
		std::optional<app::inp::ControllerHandler * const> m_controllerHandler;
		bool m_open;
		std::string m_title;
		std::uint32_t m_width, m_height;
		View m_view;
		app::del::UPtrWindow m_window;
		app::del::UPtrRenderer m_renderer;
	};

	static_assert(std::is_default_constructible<Window>::value, "Window must be default constructible");
	static_assert(std::is_destructible<Window>::value, "Window must be destructible");
	static_assert(std::is_move_constructible<Window>::value, "Window must be move constructible");
}
