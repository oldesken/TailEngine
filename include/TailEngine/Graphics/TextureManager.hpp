#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "TailEngine/Game.hpp"

class TextureManager
{
public:
	

	TextureManager();

	void clear();
	void display();

	//Tem alguma coisa errada com essas linhas aqui em baixo
	//Examinar dps

	SDL_Texture* loadTexture(const char* p_filePath);

	void drawTexture(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect);

};