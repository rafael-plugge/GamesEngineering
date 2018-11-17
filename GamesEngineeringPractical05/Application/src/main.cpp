#include "Console.h"

int main(int argc, char ** argv)
{
	using Console = app::Console;
	auto console = Console();
	std::string input = "";
	do
	{
		auto numbers = std::vector<int>();
		numbers.resize(6, 0);
		Console::writeLine("***********************************");
		Console::writeLine("*         Console Application     *");
		Console::writeLine("***********************************");
		Console::writeLine();
		for (auto & number : numbers)
		{
			Console::write("Enter number: ");
			std::cin >> number;
		}

		if (console.checkForSixNumbers(numbers))
		{
			Console::writeLine("Numbers are correct in number");
		}
		else
		{
			Console::writeLine("6 Numbers weren't typed in");
		}
		Console::writeLine(); 

		Console::writeLine("Number must range between 1 and 46");
		{
			std::size_t i = 0;
			for (bool const & result : console.checkNumbersAreBetweenRange(numbers))
			{
				auto const & num = numbers[i];
				Console::write("  Checking number (" + std::to_string(num) + ") : ");
				if (result)
				{
					Console::writeLine("within range");
				}
				else
				{
					Console::writeLine("not in range");
				}
				++i;
			}
		}
		Console::writeLine();


		Console::writeLine("Numbers must not be repeated");
		{
			std::size_t i = 0;
			for (bool const & result : console.checkNoNumbersAreRepeated(numbers))
			{
				auto const & num = numbers[i];
				Console::write("Checking number (" + std::to_string(num) + "): ");
				if (result)
				{
					Console::writeLine("is not repeated");
				}
				else
				{
					Console::writeLine("is repeated");
				}
				++i;
			}
		}
		Console::writeLine();

		Console::writeLine();
		Console::write("Enter 'y' to exit: ");
		std::cin >> input;
		Console::writeLine();
		Console::writeLine();
	} while (input != "y");
	return EXIT_SUCCESS;
}