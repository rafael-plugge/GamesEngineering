#pragma once

#include "input/Keyhandler.hpp"
#include "input/Mousehandler.hpp"
#include "deleters/SdlDeleter.hpp"
#include "graphics/WindowParameters.hpp"
#include "graphics/RenderLine.hpp"
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
		void render(app::gra::RenderLine const & line) const;
		template<class InputIterator>
		void render(InputIterator start, InputIterator const end) const;
		void display() const;

		inline constexpr auto const & isOpen() { return m_open; }
		inline constexpr auto const & getRenderer() { return m_renderer; }
		inline constexpr auto const & getWidth() { return m_width; }
		inline constexpr auto const & getHeight() { return m_height; }
	public: // Public Member Variables
	protected: // Protected Member Functions
	protected: // Protected Member Variables
	private: // Private Static Functions
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

	template<class InputIterator>
	void Window::render(InputIterator start, InputIterator const end) const
	{
		static_assert(std::is_same<std::iterator_traits<InputIterator>::value_type, app::gra::RenderLine>::value,
			"InputIterator must be a iterator whoose value_type must also be app::gra::RenderLine");

		auto points = std::vector<SDL_Point>();
		if constexpr (std::is_same<std::iterator_traits<InputIterator>::iterator_category, std::random_access_iterator_tag>::value)
		{
			points.reserve(end - start);
		}
		auto color = std::optional<math::Vector4<std::uint8_t>>();
		for (; start != end; ++start)
		{
			app::gra::RenderLine const & renderLine = *start;
			auto & startPoint = renderLine.getStart();
			points.push_back(SDL_Point{ startPoint.x, startPoint.y });
			auto & endPoint = renderLine.getEnd();
			points.push_back(SDL_Point{ endPoint.x, endPoint.y });
			if (!color.has_value()) { color = renderLine.getColor(); }
		}
		SDL_SetRenderDrawColor(m_renderer.get(), color->x, color->y, color->z, color->w);
		SDL_RenderDrawLines(m_renderer.get(), points.data(), points.size());
	}

}
