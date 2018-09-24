#include "stdafx.h"
#include "SdlDeleter.h"

void app::util::SdlDeleter::operator()(SDL_Window * pWindow) const
{
	if (pWindow == nullptr) { return; }
	SDL_DestroyWindow(pWindow);
}

void app::util::SdlDeleter::operator()(SDL_Renderer * pRenderer) const
{
	if (pRenderer == nullptr) { return; }
	SDL_DestroyRenderer(pRenderer);
}
