#ifndef _RENDER_SYSTEM_H
#define _RENDER_SYSTEM_H

#include "system/BaseSystem.h"

namespace app::sys
{
	class RenderSystem : public app::sys::BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		RenderSystem() = default;
		RenderSystem(RenderSystem const &) = default;
		RenderSystem(RenderSystem &&) = default;

		~RenderSystem() = default;

		RenderSystem & operator=(RenderSystem const &) = default;
		RenderSystem & operator=(RenderSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::nanoseconds const & dt) override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		static constexpr bool s_includeRender = false;
	private: // Private Member Variables
	};
}

#endif // !_RENDER_SYSTEM_H
