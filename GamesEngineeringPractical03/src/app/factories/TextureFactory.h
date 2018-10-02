#ifndef _TEXTURE_FACTORY_H
#define _TEXTURE_FACTORY_H

#include "BaseFactory.h"
#include "app/graphics/Texture.h"

namespace app::fact
{
	class TextureFactory : public BaseFactory<std::shared_ptr<app::gra::Texture>>
	{
	public: // Constructors/Destructor/Assignments
		TextureFactory(std::shared_ptr<SDL_Renderer> renderer, std::string const & file);

		TextureFactory() = delete;
		TextureFactory(TextureFactory const &) = default;
		TextureFactory(TextureFactory &&) = default;

		~TextureFactory() = default;

		TextureFactory & operator=(TextureFactory const &) = default;
		TextureFactory & operator=(TextureFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::shared_ptr<app::gra::Texture> create() const override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		std::shared_ptr<SDL_Renderer> m_renderer;
		std::string const & m_file;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_TEXTURE_FACTORY_H
