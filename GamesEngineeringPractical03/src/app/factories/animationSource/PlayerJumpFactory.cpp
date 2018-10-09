#include "stdafx.h"
#include "PlayerJumpFactory.h"

std::vector<SDL_Rect> app::fact::PlayerJumpFactory::create() const
{
	constexpr int width = 199;
	constexpr int height = 288;
	return {
		SDL_Rect{ width * 0, height * 0, width, height }
	};
}
