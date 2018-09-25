#ifndef _RENDER_SYSTEM_H
#define _RENDER_SYSTEM_H

#include "BaseSystem.h"
#include "app/Window.h"

namespace app::sys
{
	class RenderSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		RenderSystem(entt::DefaultRegistry & registry, std::shared_ptr<SDL_Renderer> renderer);

		RenderSystem() = delete;
		RenderSystem(RenderSystem const &) = default;
		RenderSystem(RenderSystem &&) = default;

		~RenderSystem() = default;

		RenderSystem & operator=(RenderSystem const &) = default;
		RenderSystem & operator=(RenderSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::seconds const & dt) override;
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
		std::shared_ptr<SDL_Renderer> m_renderer;
		SDL_Rect m_rect;
	};
}

#endif // !_RENDER_SYSTEM_H
