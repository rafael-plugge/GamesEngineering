#include "Console.h"

bool app::Console::checkForSixNumbers(std::vector<int> const & numbers)
{
	return (numbers.size() == 6);
}

std::vector<bool> app::Console::checkNumbersAreBetweenRange(std::vector<int> const & numbers)
{
	constexpr auto min = 1;
	constexpr auto max = 46;
	auto results = std::vector<bool>();
	for (auto const & num : numbers)
	{
		results.push_back(min < num && num < max);
	}
	return results;
}

std::vector<bool> app::Console::checkNoNumbersAreRepeated(std::vector<int> const & numbers)
{
	auto results = std::vector<bool>();
	for (size_t i = 0; i < numbers.size(); i++)
	{
		auto const & num1 = numbers[i];
		bool isRepeated = false;
		for (size_t j = 0; j < numbers.size(); j++)
		{
			if (i == j || isRepeated) { continue; }
			auto const & num2 = numbers[j];
			if (num1 == num2) { isRepeated = true; }
		}
		results.push_back(!isRepeated);
	}
	return results;
}
