#ifndef _DIMENSION_H
#define _DIMENSION_H

namespace app::comp
{
	struct Dimension
	{
	public: // Constructors/Destructor/Assignments
		Dimension() = default;
		Dimension(Dimension const &) = default;
		Dimension(Dimension &&) = default;

		~Dimension() = default;

		Dimension & operator=(Dimension const &) = default;
		Dimension & operator=(Dimension &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		int width, height;
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

#endif // !_DIMENSION_H
