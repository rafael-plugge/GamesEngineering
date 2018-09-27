#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "app/utilities/SdlDeleter.h"

namespace app::graphics
{
	class Texture
	{
	public: // Constructors/Destructor/Assignments
		Texture(app::util::UPtrRenderer const & renderer, std::string const & file);

		Texture() = default;
		Texture(Texture const &) = default;
		Texture(Texture &&) = default;

		~Texture() = default;

		Texture & operator=(Texture const &) = default;
		Texture & operator=(Texture &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		bool loadTexture(app::util::UPtrRenderer const & renderer, std::string const & file);
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
		static app::util::UPtrTexture loadTextureFromFile(app::util::UPtrRenderer const & renderer, std::string const & file);
		static app::util::UPtrSurface loadSurfaceFromFile(std::string const & file);
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		app::util::UPtrTexture m_texture;
	};
}

#endif // !_TEXTURE_H
