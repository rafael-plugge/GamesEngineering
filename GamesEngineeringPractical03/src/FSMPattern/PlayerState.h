#ifndef _PLAYER_STATE_H
#define _PLAYER_STATE_H

#include "State.h"
#include "app/graphics/Texture.h"

namespace app::fsm
{
	class PlayerState : public app::fsm::State
	{
	public: // Constructors/Destructor/Assignments
		PlayerState(app::Registry & registry, app::Entity entity, std::shared_ptr<app::gra::Texture> texture, std::vector<SDL_Rect> const & frames);

		PlayerState(PlayerState const &) = default;
		PlayerState(PlayerState &&) = default;

		~PlayerState() = default;

		PlayerState & operator=(PlayerState const &) = default;
		PlayerState & operator=(PlayerState &&) = default;

	public: // Public Static Functions
		static std::shared_ptr<PlayerState> instance() { return s_ptr; }
	public: // Public Member Functions
		virtual void update(app::seconds const & dt) override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Registry & m_registry;
		app::Entity m_entity;
		std::shared_ptr<app::gra::Texture> m_texture;
		std::vector<SDL_Rect> m_frames;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		static std::shared_ptr<PlayerState> s_ptr;
	private: // Private Member Variables
	};
}

#endif // !_PLAYER_STATE_H
