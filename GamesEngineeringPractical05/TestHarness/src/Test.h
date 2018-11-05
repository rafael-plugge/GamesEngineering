#ifndef _TEST_PROGRAM_H
#define _TEST_PROGRAM_H

#include <cassert>
#include <iterator>

namespace app
{
	class Test
	{
	public: // Constructors/Destructor/Assignments
		Test() = delete;
		Test(Test const &) = delete;
		Test(Test &&) = delete;

		~Test() = delete;

		Test & operator=(Test const &) = delete;
		Test & operator=(Test &&) = delete;

	public: // Public Static Functions
		static void checkForSixNumbers(std::initializer_list<int> const & numbers);
		static void checkNumbersAreBetweenRange(std::initializer_list<int> const & numbers);
		static void checkNoNumbersAreRepeated(std::initializer_list<int> const & numbers);
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_TEST_PROGRAM_H