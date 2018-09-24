#ifndef _SDL_DELETER_H
#define _SDL_DELETER_H

namespace app::util
{
	class SdlDeleter
	{
	public:
		SdlDeleter() = default;
		~SdlDeleter() = default;
		void operator()(SDL_Window * pWindow) const;
		void operator()(SDL_Renderer * pRenderer) const;
	};

}

#endif // !_SDL_DELETER_H
