#include "stdafx.hpp"
#include "Window.hpp"

std::optional<app::gra::Window const * const> app::gra::Window::s_pWindow = std::nullopt;

app::gra::Window::Window()
	: m_keyhandler()
	, m_mousehandler()
	, m_controllerHandler()
	, m_open(false)
	, m_title()
	, m_width(0u)
	, m_height(0u)
	, m_view()
	, m_window(nullptr)
	, m_renderer(nullptr)
{
}

app::gra::Window::Window(WindowParameters params)
	: m_keyhandler()
	, m_mousehandler()
	, m_controllerHandler()
	, m_open(true)
	, m_title(params.title)
	, m_width(params.width)
	, m_height(params.height)
	, m_view{ math::Vector2i{ params.width / 2, params.height / 2 }, math::Vector2i{ params.width, params.height } }
	, m_window(nullptr)
	, m_renderer(nullptr)
{
	m_open = this->init();
}

app::gra::Window::Window(
	app::inp::KeyHandler & keyHandler
	, app::inp::MouseHandler & mouseHandler
	, app::inp::ControllerHandler & controllerHandler
	, app::gra::WindowParameters params
)
	: m_keyhandler(&keyHandler)
	, m_mousehandler(&mouseHandler)
	, m_controllerHandler(&controllerHandler)
	, m_open(true)
	, m_title(params.title)
	, m_width(params.width)
	, m_height(params.height)
	, m_view{ math::Vector2i{ params.width / 2, params.height / 2 }, math::Vector2i{ params.width, params.height } }
	, m_window(nullptr)
	, m_renderer(nullptr)
{
	m_open = this->init();
}

app::gra::Window::~Window()
{
}

bool app::gra::Window::init(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler, app::inp::ControllerHandler & controllerHandler, WindowParameters params)
{
	if (m_open) { throw std::exception("Tried to initialize a window that has already been initialized"); }
	m_controllerHandler.emplace(&controllerHandler);
	return this->init(keyHandler, mouseHandler, std::move(params));
}

bool app::gra::Window::init(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler, WindowParameters params)
{
	if (m_open) { throw std::exception("Tried to initialize a window that has already been initialized"); }
	m_mousehandler.emplace(&mouseHandler);
	return this->init(keyHandler, std::move(params));
}

bool app::gra::Window::init(app::inp::KeyHandler & keyHandler, WindowParameters params)
{
	if (m_open) { throw std::exception("Tried to initialize a window that has already been initialized"); }
	m_keyhandler.emplace(&keyHandler);
	return this->init(std::move(params));
}

bool app::gra::Window::init(WindowParameters params)
{
	if (m_open) { throw std::exception("Tried to initialize a window that has already been initialized"); }
	m_title = params.title;
	m_width = params.width;
	m_height = params.height;
	m_view = app::gra::View{ math::Vector2i{ params.width / 2, params.height / 2 }, math::Vector2i{ params.width, params.height } };
	m_window.reset(nullptr);
	m_renderer.reset(nullptr);
	return m_open = this->init();
}

void app::gra::Window::setView(app::gra::View const & view)
{
	m_view = view;
}

void app::gra::Window::resetView()
{
	m_view = app::gra::View{ {m_width / 2, m_height / 2}, {m_width, m_height} };
}

void app::gra::Window::pollEvents()
{
	typedef SDL_EventType EventType;
	SDL_Event sdlEvent;
	auto * const controllerHandler = m_controllerHandler.value_or(nullptr);
	while (SDL_PollEvent(&sdlEvent))
	{
		if (auto * const mouseHandler = m_mousehandler.value_or(nullptr); m_mousehandler.has_value())
		{
			switch (sdlEvent.type)
			{
				case EventType::SDL_MOUSEMOTION:
					mouseHandler->updatePosition(sdlEvent.motion.x, sdlEvent.motion.y);
					break;
				case EventType::SDL_MOUSEBUTTONUP:
					mouseHandler->updateButton(sdlEvent.button.button, false);
					break;
				case EventType::SDL_MOUSEBUTTONDOWN:
					mouseHandler->updateButton(sdlEvent.button.button, true);
					break;
				default:
					break;
			}
		}
		if (auto * const keyHandler = m_keyhandler.value_or(nullptr); m_keyhandler.has_value())
		{
			switch (sdlEvent.type)
			{
				case EventType::SDL_KEYUP:
					keyHandler->updateKey(sdlEvent.key.keysym.sym, false);
					break;
				case EventType::SDL_KEYDOWN:
					keyHandler->updateKey(sdlEvent.key.keysym.sym, true);
					if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) { m_open = false; }
					break;
				default:
					break;
			}
		}
		if (auto * const controllerHandler = m_controllerHandler.value_or(nullptr); m_controllerHandler.has_value())
		{
			switch (sdlEvent.type)
			{
				case EventType::SDL_CONTROLLERBUTTONUP:
					controllerHandler->updateButton(sdlEvent.cbutton.which, static_cast<app::inp::ControllerButtonCode>(sdlEvent.cbutton.button), false);
					break;
				case EventType::SDL_CONTROLLERBUTTONDOWN:
					controllerHandler->updateButton(sdlEvent.cbutton.which, static_cast<app::inp::ControllerButtonCode>(sdlEvent.cbutton.button), true);
					break;
				case EventType::SDL_CONTROLLERAXISMOTION:
					controllerHandler->updateAxis(sdlEvent.caxis.which, static_cast<app::inp::ControllerAxisCode>(sdlEvent.caxis.axis), sdlEvent.caxis.value);
					break;
				case EventType::SDL_CONTROLLERDEVICEADDED:
					controllerHandler->addController(sdlEvent.cdevice.which);
					break;
				case EventType::SDL_CONTROLLERDEVICEREMOVED:
					controllerHandler->removeController(sdlEvent.cdevice.which);
					break;
				default:
					break;
			}
		}
		switch (sdlEvent.type)
		{
			case EventType::SDL_QUIT:
				m_open = false;
				break;
			default:
				break;
		}
	}
}

void app::gra::Window::clear() const
{
	auto lock = std::lock_guard<decltype(app::gra::Texture::s_sdlMutex)>(app::gra::Texture::s_sdlMutex);
	SDL_SetRenderDrawColor(m_renderer.get(), s_BG_COLOR.r, s_BG_COLOR.g, s_BG_COLOR.b, s_BG_COLOR.a);
	SDL_RenderClear(m_renderer.get());
}

void app::gra::Window::render(app::gra::RenderRect const & rect) const
{
	constexpr auto FLIP_FLAG = SDL_RendererFlip::SDL_FLIP_NONE;
	auto const & position = static_cast<math::Vector2i>(rect.getPosition());
	auto const & origin = static_cast<math::Vector2i>(rect.getOrigin());
	auto const & size = static_cast<math::Vector2i>(rect.getSize());
	auto const & screenSize = math::Vector2f{ static_cast<float>(m_width), static_cast<float>(m_height) };
	auto const & scale = screenSize / static_cast<math::Vector2f>(m_view.size);
	auto const & halfSize = m_view.size / 2;
	auto const & destination = SDL_Rect{
		position.x - origin.x - (m_view.position.x - halfSize.x),
		position.y - origin.y - (m_view.position.y - halfSize.y),
		static_cast<int32_t>(size.x * scale.x),
		static_cast<int32_t>(size.y * scale.y)
	};
	auto const & center = SDL_Point{
		static_cast<int32_t>(origin.x * scale.x),
		static_cast<int32_t>(origin.y * scale.y)
	};
	auto const & source = rect.getSourceRect();
	auto const & sourceMathRect = static_cast<math::Recti>(source.value_or(math::Rectd()));
	auto const & sourceRect = SDL_Rect{
		  static_cast<std::int32_t>(sourceMathRect.x)
		, static_cast<std::int32_t>(sourceMathRect.y)
		, static_cast<std::int32_t>(sourceMathRect.w)
		, static_cast<std::int32_t>(sourceMathRect.h)
	};
	SDL_RenderCopyEx(m_renderer.get(), rect.getTexture(), source.has_value() ? &sourceRect : nullptr, &destination, rect.getRotation(), &center, FLIP_FLAG);
}

void app::gra::Window::render(std::unique_ptr<SDL_Texture> const & texture, SDL_Rect const & rect, std::optional<SDL_Rect> source) const
{
	SDL_RenderCopy(m_renderer.get(), texture.get(), source.has_value() ? &source.value() : nullptr, &rect);
}

void app::gra::Window::render(std::shared_ptr<SDL_Texture> texture, SDL_Rect const & rect, std::optional<SDL_Rect> source) const
{
	SDL_RenderCopy(m_renderer.get(), texture.get(), source.has_value() ? &source.value() : nullptr, &rect);
}

void app::gra::Window::display() const
{
	auto lock = std::lock_guard<decltype(app::gra::Texture::s_sdlMutex)>(app::gra::Texture::s_sdlMutex);
	SDL_RenderPresent(m_renderer.get());
}

app::math::Vector2u app::gra::Window::getSize()
{
	if (!s_pWindow.has_value()) { throw std::exception("Tried to retrieve size of a window that doesn't exist."); }
	auto const * const pWindow = s_pWindow.value();
	return math::Vector2u{ pWindow->m_width, pWindow->m_height };
}

bool app::gra::Window::init()
{
	try
	{
		if (SDL_Init(SDL_INIT_VIDEO) != NULL)
		{
			Console::writeLine("ERROR: Failed to initialize SDL Video subsystem");
			return false;
		}
		if (!this->initWindow())
		{
			Console::writeLine({ "ERROR: Failed to initialize SDL Window::\"", m_title, "\"\n  ", SDL_GetError() });
			return false;
		}
		if (!this->initRenderer(m_window))
		{
			Console::writeLine({ "ERROR: Failed to initialize SDL Renderer from the SDL Window::\"", m_title, "\"\n  ", SDL_GetError() });
			return false;
		}
		app::gra::Window::s_pWindow.emplace(this);
		return true;
	}
	catch (const std::exception& e)
	{
		Console::writeLine({ "ERROR: Exception has occurred [", e.what(), "]" });
		return false;
	}
}

bool app::gra::Window::initWindow()
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

bool app::gra::Window::initRenderer(app::del::UPtrWindow const & uptrSdlWindow)
{
	SDL_Renderer * pRenderer = nullptr;
	
	pRenderer = SDL_CreateRenderer(uptrSdlWindow.get(), -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);

	const bool success = nullptr != pRenderer;
	if (success) { m_renderer.reset(pRenderer); }
	return success;
}
