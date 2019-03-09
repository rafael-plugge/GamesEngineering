#include "stdafx.hpp"
#include "utilities/Console.hpp"
#include "utilities/Random.hpp"

bool inOne = false,
	inTwo = false;
int last = 1;

void csThreadOne()
{
	while (true)
	{
		inOne = true; last = 1;
		while (inTwo && last == 1) continue;
		// critical section
		app::cout::wl("Thread[1] critical section");
		inOne = false;
	}
}

void csThreadTwo()
{
	while (true)
	{
		inTwo = true; last = 2;
		while (inOne && last == 2) continue;
		// critical section
		app::cout::wl("Thread[2] critical section");
		inTwo = false;
	}
}

int main(int argc, char const ** argv)
{
	auto csOne = std::thread(csThreadOne);
	auto csTwo = std::thread(csThreadTwo);
	csOne.join();
	csTwo.join();
	std::cin.get();
	return EXIT_SUCCESS;
}
