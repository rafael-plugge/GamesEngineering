#include "stdafx.h"
#include "SdlDeleter.h"

void util::SdlDeleter::operator()(SDL_Window * pWindow) const
{
	if (pWindow == nullptr) { return; }
	SDL_DestroyWindow(pWindow);
}

void util::SdlDeleter::operator()(SDL_Renderer * pRenderer) const
{
	if (pRenderer == nullptr) { return; }
	SDL_DestroyRenderer(pRenderer);
}

void util::SdlDeleter::operator()(SDL_Texture * pTexture) const
{
	if (pTexture == nullptr) { return; }
	SDL_DestroyTexture(pTexture);
}

void util::SdlDeleter::operator()(SDL_Surface * pSurface) const
{
	if (pSurface == nullptr) { return; }
	SDL_FreeSurface(pSurface);
}
