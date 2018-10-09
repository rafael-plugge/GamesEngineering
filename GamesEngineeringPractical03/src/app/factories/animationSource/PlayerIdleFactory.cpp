#include "stdafx.h"
#include "PlayerIdleFactory.h"

std::vector<SDL_Rect> app::fact::PlayerIdleFactory::create() const
{
	// player idle anim frames
	// framesInX = 5, framesInY = 6

	constexpr int width = 199;
	constexpr int height = 288;
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
