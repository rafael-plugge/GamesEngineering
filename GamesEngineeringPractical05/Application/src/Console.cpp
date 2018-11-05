#include "Console.h"

int app::Console::run()
{
	std::string input = "";
	do
	{
		auto numbers = std::vector<int>();
		numbers.resize(6, 0);
		writeLine("***********************************");
		writeLine("*         Console Application     *");
		writeLine("***********************************");
		writeLine();
		for (auto & number : numbers)
		{
			write("Enter number: ");
			std::cin >> number;
		}

		this->checkForSixNumbers(numbers);
		this->checkNumbersAreBetweenRange(numbers);
		this->checkNoNumbersAreRepeated(numbers);

		writeLine();
		write("Enter 'y' to exit: ");
		std::cin >> input;
		writeLine(); 
		writeLine();
	} while (input != "y");
	return EXIT_SUCCESS;
}

void app::Console::checkForSixNumbers(std::vector<int> const & numbers)
{
	if (numbers.size() == 6)
	{
		writeLine("Numbers are correct in number");
	}
	else
	{
		writeLine("6 Numbers weren't typed in");
	}
	writeLine();
}

void app::Console::checkNumbersAreBetweenRange(std::vector<int> const & numbers)
{
	constexpr auto min = 1;
	constexpr auto max = 46;
	writeLine("Number must range between " + std::to_string(min) + " and " + std::to_string(max));
	for (auto const & num : numbers)
	{
		write("  Checking number (" + std::to_string(num) + ") : ");
		if (min < num && num < max)
		{
			writeLine("within range");
		}
		else if (!(min < num))
		{
			writeLine("too small");
		}
		else if (!(num < max))
		{
			writeLine("too large");
		}
	}
	writeLine();
}

void app::Console::checkNoNumbersAreRepeated(std::vector<int> const & numbers)
{
	writeLine("Numbers must not be repeated");
	for (size_t i = 0; i < numbers.size(); i++)
	{
		auto const & num1 = numbers[i];
		writeLine("Checking number (" + std::to_string(num1) + "):");
		for (size_t j = 0; j < numbers.size(); j++)
		{
			if (i == j) { continue; }
			auto const & num2 = numbers[j];
			if (num1 != num2)
			{
				writeLine("  != (" + std::to_string(num2) + ")");
			}
			else
			{
				writeLine("  == (" + std::to_string(num2) + ")");
			}
		}
	}
	writeLine();
}
