#include <cstdlib>
#include <cassert>
#include <array>

#include "Test.h"

int main(int argc, char** argv)
{
	// Success case
	std::initializer_list<int> t2 = { 1, 2, 3, 4, 5, 6 };
	app::Test::checkForSixNumbers(t2);
	app::Test::checkNumbersAreBetweenRange(t2);
	app::Test::checkNoNumbersAreRepeated(t2);

	// Fail case
	std::initializer_list<int> t1 = { 0, 2, 4, 70, 30, 20, 10, 20, 23, 12 };
	app::Test::checkForSixNumbers(t1);
	app::Test::checkNumbersAreBetweenRange(t1);
	app::Test::checkNoNumbersAreRepeated(t1);

	return EXIT_SUCCESS;
}