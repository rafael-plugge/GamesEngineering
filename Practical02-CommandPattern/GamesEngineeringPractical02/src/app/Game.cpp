#include "stdafx.h"
#include "Game.h"

app::Game::Game()
	: m_window("Games Engineering", 1366u, 768u)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != NULL)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL\nApplication failed to launch");
	}
}

app::Game::~Game()
{
	SDL_Quit();
}

int app::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	constexpr std::chrono::nanoseconds updateStepNano =
		std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	clock::time_point deltaTimePoint = clock::now();
	clock::duration elapsedTime = updateStepNano;

	if (!this->init()) { return EXIT_FAILURE; }

	while (m_window.isOpen())
	{
		m_window.pollEvents();
		elapsedTime += std::chrono::duration_cast<clock::duration>(clock::now() - deltaTimePoint);
		deltaTimePoint = clock::now();
		while (elapsedTime > updateStepNano)
		{
			this->update(s_updateStep);
			elapsedTime -= updateStepNano;
		}
		this->render();
	}

	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	return true;
}

void app::Game::update(app::seconds const & dt)
{
}

void app::Game::render()
{
	m_window.clear();
	m_window.display();
}
