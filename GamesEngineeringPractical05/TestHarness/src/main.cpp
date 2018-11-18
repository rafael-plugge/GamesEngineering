#include <cstdlib>
#include <cassert>
#include <array>

#include "../../Application/src/Console.h"

int main(int argc, char** argv)
{
	// Success case
	{
		std::initializer_list<int> t2 = { 1, 2, 3, 4, 5, 6 };
		{
			auto console = app::Console();
			auto result = console.checkForSixNumbers(t2);
			assert(result == true);
		}
		{
			auto console = app::Console();
			auto results = console.checkNumbersAreBetweenRange(t2);
			// Check that there are no false booleans in results
			assert(std::find_if(results.begin(), results.end(), [](bool const & result) { return result != false; }) != results.end());
		}
		{
			auto console = app::Console();
			auto results = console.checkNoNumbersAreRepeated(t2);
			assert(std::find_if(results.begin(), results.end(), [](bool const & result) { return result != false; }) != results.end());
		}
	}
	// Fail case
	{
		std::initializer_list<int> t1 = { 0, 2, 4, 70, 30, 20, 10, 20, 23, 12 };
		{
			auto console = app::Console();
			auto result = console.checkForSixNumbers(t1);
			assert(result == false);
		}
		{
			auto console = app::Console();
			auto results = console.checkNumbersAreBetweenRange(t1);
			// Check that there is at least one false boolean in results
			assert(std::find_if(results.begin(), results.end(), [](bool const & result) { return result == false; }) != results.end());
		}
		{
			auto console = app::Console();
			auto results = console.checkNoNumbersAreRepeated(t1);
			assert(std::find_if(results.begin(), results.end(), [](bool const & result) { return result == false; }) != results.end());
		}
	}

	return EXIT_SUCCESS;
}