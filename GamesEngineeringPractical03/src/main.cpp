#include "stdafx.h"
#include "app/Game.h"

int main(int argc, char** argv)
{
	SDL_SetMainReady();
	return app::Game().run();
}