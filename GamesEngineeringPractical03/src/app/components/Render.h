﻿#ifndef _RENDER_H
#define _RENDER_H

namespace app::comp
{
	struct Render
	{
	public: // Constructors/Destructor/Assignments
		Render() = default;
		Render(Render const &) = default;
		Render(Render &&) = default;

		~Render() = default;

		Render & operator=(Render const &) = default;
		Render & operator=(Render &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::shared_ptr<SDL_Texture> texture;
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

#endif // !_RENDER_H
