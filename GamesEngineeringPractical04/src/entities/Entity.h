#ifndef _ENTITY_H
#define _ENTITY_H

#include "component/Component.h"

namespace app::ent
{
	class Entity
	{
	public: // Constructors/Destructor/Assignments
		Entity() = default;
		Entity(Entity const &) = default;
		Entity(Entity &&) = default;

		~Entity() = default;

		Entity & operator=(Entity const &) = default;
		Entity & operator=(Entity &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		bool operator==(Entity const & ent) const { return this->getId() == ent.getId(); }

		void addComp(app::comp::Component c) { m_components.push_back(std::move(c)); }
		void addComp(std::initializer_list<app::comp::Component> cs) { m_components.insert(m_components.end(), std::move(cs)); }
		void removeComp(app::comp::Component c) {}

		std::vector<app::comp::Component> & getComps() { return m_components; }
		std::string_view getName() { return m_name; }
		void setName(std::string name) { m_name = std::move(name); }
		std::uint32_t const & getId() const { return m_id; }
		void setId(std::uint32_t id) { m_id = id; }
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::uint32_t m_id;
		std::string m_name;
		std::vector<app::comp::Component> m_components;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_ENTITY_H
