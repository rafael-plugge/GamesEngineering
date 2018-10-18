#ifndef _BASE_COMPONENT_H
#define _BASE_COMPONENT_H

namespace app::comp
{
	struct Component
	{
	public: // Constructors/Destructor/Assignments
		Component() = default;
		Component(Component const &) = default;
		Component(Component &&) = default;

		~Component() = default;

		Component & operator=(Component const &) = default;
		Component & operator=(Component &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		std::string_view getName() const { return m_name; }
		void setName(std::string name) { m_name = std::move(name); }
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::string m_name;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_BASE_COMPONENT_H
