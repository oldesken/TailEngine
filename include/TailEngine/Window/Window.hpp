#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Window
{
public:

	Window(const char* p_title, int p_w, int p_h);

	SDL_Window* window;

	int getRefreshRate();
	void cleanUp();

private:
	
	
};

