#include "stdafx.hpp"
#include "Game.hpp"
#include <Windows.h>

/// 
/// Clear the console screen using Windows API
/// Retrieved from https://stackoverflow.com/a/5866648
///
void clearScreen(char const & fill = ' ')
{
	using Coordinates = COORD;
	using BufferInfo = CONSOLE_SCREEN_BUFFER_INFO;
	using ComHandle = HANDLE;
	using uint48_t = DWORD;

	auto tl = Coordinates{ 0,0 };
	auto s = BufferInfo();
	ComHandle console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	uint48_t written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

int main(int argc, char const ** argv)
{
	using clock = std::chrono::high_resolution_clock;
	constexpr app::time::nanoseconds UPDATE_STEP =
		app::time::toNanos(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	constexpr auto UPDATE_STEP_SEC = app::time::toSeconds(UPDATE_STEP);
	constexpr auto ONE_SECOND =
		app::time::toNanos(std::chrono::duration<double, std::milli>(30.0 * 1000.0));
	clock::time_point deltaTimePoint = clock::now();
	app::time::nanoseconds elapsedTime = UPDATE_STEP;
	app::time::nanoseconds deltaRenderStep = app::time::nanoseconds::zero();
	app::time::nanoseconds fpsTimer = app::time::nanoseconds::zero();
	std::uint64_t fpsCounter = 0u;

	auto game = app::Game();
	if (!game.init()) { std::cin.get(); return EXIT_FAILURE; }

	while (game.isRunning())
	{
		game.pollEvents();
		deltaRenderStep =
			(elapsedTime += app::time::toNanos(clock::now() - deltaTimePoint));
		deltaTimePoint = clock::now();
		fpsTimer += elapsedTime;
		for (; elapsedTime > UPDATE_STEP; elapsedTime -= UPDATE_STEP)
		{
			game.update(UPDATE_STEP_SEC);
		}
		game.render(app::time::toSeconds(deltaRenderStep));
		if (fpsTimer > ONE_SECOND)
		{
			fpsTimer -= ONE_SECOND;
			clearScreen();
			app::cout::wl({ "FPS: ", fpsCounter });
			fpsCounter = 0u;
		}
		else
		{
			++fpsCounter;
		}
	}

	return EXIT_SUCCESS;
}
