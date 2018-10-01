#ifndef _BASE_SYSTEM_H
#define _BASE_SYSTEM_H

namespace app::sys
{
	class BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		BaseSystem(app::Registry & registry);

		BaseSystem() = delete;
		BaseSystem(BaseSystem const &) = default;
		BaseSystem(BaseSystem &&) = default;

		~BaseSystem() = default;

		BaseSystem & operator=(BaseSystem const &) = default;
		BaseSystem & operator=(BaseSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::seconds const & dt) = 0;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		entt::DefaultRegistry & m_registry;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_BASE_SYSTEM_H
