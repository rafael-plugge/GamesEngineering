#include "stdafx.h"
#include "Window.h"

app::Window::Window(std::string const & title, std::size_t const & width, std::size_t const & height)
	: m_open(true)
	, m_title(title)
	, m_width(width)
	, m_height(height)
	, m_window(nullptr)
	, m_renderer(nullptr)
{
	m_open = this->init();
}

app::Window::~Window()
{
}

void app::Window::pollEvents()
{
	typedef SDL_EventType EventType;
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case EventType::SDL_QUIT:
			m_open = false;
			break;
		case EventType::SDL_KEYUP:
			break;
		case EventType::SDL_KEYDOWN:
			if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) { m_open = false; }
			break;
		default:
			break;
		}
	}
}

void app::Window::clear() const
{
	SDL_SetRenderDrawColor(m_renderer.get(), s_BG_COLOR.r, s_BG_COLOR.g, s_BG_COLOR.b, s_BG_COLOR.a);
	SDL_RenderClear(m_renderer.get());
}

void app::Window::display() const
{
	SDL_RenderPresent(m_renderer.get());
}

bool app::Window::init()
{
	try
	{
		if (SDL_Init(SDL_INIT_VIDEO) != NULL)
		{
			std::string const errorMsg("Failed to initialize SDL Video subsystem");
			SDL_LogCritical(SDL_LOG_CATEGORY_VIDEO, errorMsg.c_str());
			return false;
		}
		if (!this->initWindow())
		{
			std::string errorMsg("Failed to initialize SDL Window::\"");
			errorMsg.append(m_title.c_str()).append("\"\n  ").append(SDL_GetError());
			SDL_LogCritical(SDL_LOG_CATEGORY_VIDEO, errorMsg.c_str());
			return false;
		}
		if (!this->initRenderer(m_window))
		{
			std::string errorMsg("Faild to initialize SDL Renderer from the SDL Window::\"");
			errorMsg.append(m_title.c_str()).append("\"\n  ").append(SDL_GetError());
			SDL_LogCritical(SDL_LOG_CATEGORY_RENDER, errorMsg.c_str());
			return false;
		}

		return true;
	}
	catch (const std::exception& e)
	{
		SDL_LogError(SDL_LOG_CATEGORY_VIDEO, e.what());
		return false;
	}
}

bool app::Window::initWindow()
{
	typedef SDL_WindowFlags WindowFlags;
	constexpr auto centerPos = SDL_WINDOWPOS_CENTERED;
	constexpr auto windowFlags = WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI | WindowFlags::SDL_WINDOW_SHOWN;
	SDL_Window * pWindow = nullptr;

	pWindow = SDL_CreateWindow(m_title.c_str(), centerPos, centerPos, m_width, m_height, windowFlags);

	const bool success = nullptr != pWindow;
	if (success) { m_window.reset(pWindow); }
	return success;
}

bool app::Window::initRenderer(app::Window::UPtrWindow const & uptrSdlWindow)
{
	SDL_Renderer * pRenderer = nullptr;
	
	pRenderer = SDL_CreateRenderer(uptrSdlWindow.get(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

	const bool success = nullptr != pRenderer;
	if (success) { m_renderer.reset(pRenderer, app::util::SdlDeleter()); }
	return success;
}
