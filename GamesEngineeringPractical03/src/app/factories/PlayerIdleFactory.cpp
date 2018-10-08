#include "stdafx.h"
#include "PlayerIdleFactory.h"

std::vector<SDL_Rect> app::fact::PlayerIdleFactory::create() const
{
	// player idle anim frames
	// width = 199, height = 288
	// framesInX = 5, framesInY = 6
	return {
		SDL_Rect{ 199 * 0, 288 * 0, 199, 288 },
		SDL_Rect{ 199 * 1, 288 * 0, 199, 288 },
		SDL_Rect{ 199 * 2, 288 * 0, 199, 288 },
		SDL_Rect{ 199 * 3, 288 * 0, 199, 288 },
		SDL_Rect{ 199 * 4, 288 * 0, 199, 288 },
		SDL_Rect{ 199 * 0, 288 * 1, 199, 288 },
		SDL_Rect{ 199 * 1, 288 * 1, 199, 288 },
		SDL_Rect{ 199 * 2, 288 * 1, 199, 288 },
		SDL_Rect{ 199 * 3, 288 * 1, 199, 288 },
		SDL_Rect{ 199 * 4, 288 * 1, 199, 288 },
		SDL_Rect{ 199 * 0, 288 * 2, 199, 288 },
		SDL_Rect{ 199 * 1, 288 * 2, 199, 288 },
		SDL_Rect{ 199 * 2, 288 * 2, 199, 288 },
		SDL_Rect{ 199 * 3, 288 * 2, 199, 288 },
		SDL_Rect{ 199 * 4, 288 * 2, 199, 288 },
		SDL_Rect{ 199 * 0, 288 * 3, 199, 288 },
		SDL_Rect{ 199 * 1, 288 * 3, 199, 288 },
		SDL_Rect{ 199 * 2, 288 * 3, 199, 288 },
		SDL_Rect{ 199 * 3, 288 * 3, 199, 288 },
		SDL_Rect{ 199 * 4, 288 * 3, 199, 288 }
	};
}
