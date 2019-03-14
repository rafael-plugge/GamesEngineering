#include "stdafx.hpp"
#include "utilities/Console.hpp"

constexpr int NUMBER_OF_PROCESSES = 5;
std::array<std::int32_t, NUMBER_OF_PROCESSES> in, last;

void csThread(int const i)
{
	while (true)
	{
		for (int j = 0; j < NUMBER_OF_PROCESSES; ++j)
		{
			in.at(i) = j; last.at(j) = i;
			for (int k = 0; k < NUMBER_OF_PROCESSES; k++)
			{
				if (k != i)
					while (in.at(k) >= in.at(i) && last.at(j) == i) { continue; }
			}
		}
		// critical section
		app::cout::wl({ "Thread[", i, "] critical section" });
		in.at(i) = 0;
	}
}

int main(int argc, char const ** argv)
{
	in.fill(0); last.fill(0);
	auto threadPool = std::vector<std::thread>();
	threadPool.reserve(NUMBER_OF_PROCESSES);
	for (int i = 0; i < NUMBER_OF_PROCESSES; ++i)
	{
		threadPool.push_back(std::thread(csThread, i));
	}
	for (auto & thread : threadPool)
	{
		thread.join();
	}
	std::cin.get();
	return EXIT_SUCCESS;
}
