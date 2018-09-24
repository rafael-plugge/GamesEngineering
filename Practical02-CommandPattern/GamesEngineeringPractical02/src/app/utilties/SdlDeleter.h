#ifndef _SDL_DELETER_H
#define _SDL_DELETER_H

namespace app::util
{
	class SdlDeleter
	{
	public: // Constructors/Destructor/Assignments
		SdlDeleter() = default;
		SdlDeleter(SdlDeleter const &) = default;
		SdlDeleter(SdlDeleter &&) = default;

		~SdlDeleter() = default;

		SdlDeleter & operator=(SdlDeleter const &) = default;
		SdlDeleter & operator=(SdlDeleter &&) = default;
	public: // Public Static Functions
	public: // Public Member Functions
		void operator()(SDL_Window * pWindow) const;
		void operator()(SDL_Renderer * pRenderer) const;
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
	};

}

#endif // !_SDL_DELETER_H
