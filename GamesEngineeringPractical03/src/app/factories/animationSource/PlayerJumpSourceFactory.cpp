#include "stdafx.h"
#include "PlayerJumpSourceFactory.h"

std::vector<SDL_Rect> app::fact::PlayerJumpSourceFactory::create() const
{
	constexpr int width = 234;
	constexpr int height = 344;
	return {
		SDL_Rect{ width * 0, height * 0, width, height },
		SDL_Rect{ width * 1, height * 0, width, height },
		SDL_Rect{ width * 2, height * 0, width, height },
		SDL_Rect{ width * 3, height * 0, width, height },
		SDL_Rect{ width * 4, height * 0, width, height },
		SDL_Rect{ width * 0, height * 1, width, height },
		SDL_Rect{ width * 1, height * 1, width, height },
		SDL_Rect{ width * 2, height * 1, width, height },
		SDL_Rect{ width * 3, height * 1, width, height },
		SDL_Rect{ width * 4, height * 1, width, height },
		SDL_Rect{ width * 0, height * 2, width, height },
		SDL_Rect{ width * 1, height * 2, width, height },
		SDL_Rect{ width * 2, height * 2, width, height },
		SDL_Rect{ width * 3, height * 2, width, height },
		SDL_Rect{ width * 4, height * 2, width, height },
		SDL_Rect{ width * 0, height * 3, width, height },
		SDL_Rect{ width * 1, height * 3, width, height },
		SDL_Rect{ width * 2, height * 3, width, height },
		SDL_Rect{ width * 3, height * 3, width, height },
		SDL_Rect{ width * 4, height * 3, width, height }
	};
}
