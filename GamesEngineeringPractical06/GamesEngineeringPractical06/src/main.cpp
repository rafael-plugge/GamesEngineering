#include <array>
#include <thread>

int buf = 0, p = 0, c = 0;
constexpr int NUM = 3;

void producer(std::array<int, NUM> & a)
{
	while (p < NUM)
	{
		while (p == c)
		{
			buf = a[p];
			++p;
		}
	}

}

void consumer(std::array<int, NUM> & b)
{
	while (c < NUM)
	{
		while (p > c)
		{
			b[c] = buf;
			++c;
		}
	}
}

int main(int argc, char const *argv[])
{
	std::array<int, NUM> a = { 4, 5, 6 };
	std::array<int, NUM> b = { 0, 0, 0 };
	auto consumerThread = std::thread(consumer, std::ref(b));
	auto producerThread = std::thread(producer, std::ref(a));
	producerThread.join();
	consumerThread.join();
	return 0;
}