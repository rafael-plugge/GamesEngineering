#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace app
{
	class Console
	{
	public: // Constructors/Destructor/Assignments
		Console() = default;
		Console(Console const &) = default;
		Console(Console &&) = default;

		~Console() = default;

		Console & operator=(Console const &) = default;
		Console & operator=(Console &&) = default;

	public: // Public Static Functions
		static inline void writeLine(std::string const & str) { std::cout << str << std::endl; }
		static inline void writeLine() { std::cout << std::endl; }
		static inline void write(std::string const & str) { std::cout << str; }
	public: // Public Member Functions
		bool checkForSixNumbers(std::vector<int> const & numbers);
		std::vector<bool> checkNumbersAreBetweenRange(std::vector<int> const & numbers);
		std::vector<bool> checkNoNumbersAreRepeated(std::vector<int> const & numbers);
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

#endif // !_CONSOLE_H
