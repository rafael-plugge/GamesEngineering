#ifndef _PLAYER_FACTORY_H
#define _PLAYER_FACTORY_H

#include "EntityFactory.h"
#include "app/graphics/Texture.h"

namespace app::fact
{
	class PlayerFactory : public EntityFactory
	{
	public: // Constructors/Destructor/Assignments
		PlayerFactory(app::Registry & registry, std::shared_ptr<SDL_Renderer> renderer);

		PlayerFactory() = delete;
		PlayerFactory(PlayerFactory const &) = default;
		PlayerFactory(PlayerFactory &&) = default;

		~PlayerFactory() = default;

		PlayerFactory & operator=(PlayerFactory const &) = default;
		PlayerFactory & operator=(PlayerFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity create() const override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::shared_ptr<SDL_Renderer> m_renderer;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_PLAYER_FACTORY_H
