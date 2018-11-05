#include "Test.h"

void app::Test::checkForSixNumbers(std::initializer_list<int> const & numbers)
{
	assert(numbers.size() == 6);
}

void app::Test::checkNumbersAreBetweenRange(std::initializer_list<int> const & numbers)
{
	constexpr auto min = 1;
	constexpr auto max = 46;
	for (auto const & num : numbers)
	{
		assert(min < num && num < max);
	}
}

void app::Test::checkNoNumbersAreRepeated(std::initializer_list<int> const & numbers)
{
	for (auto const & num1 : numbers)
	{
		for (auto const & num2 : numbers)
		{
			if (num1 == num2) { continue; }
			assert(num1 != num2);
		}
	}
}
