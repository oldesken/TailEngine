#include "TextureManager.hpp"

TextureManager::TextureManager()
{

}

SDL_Texture* TextureManager::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(Game::renderer, p_filePath);

	if (texture == NULL)
		std::cout << "failed to import texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void TextureManager::drawTexture(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect destRect)
{
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
}

void TextureManager::clear()
{
	SDL_RenderClear(Game::renderer);
}

void TextureManager::display()
{
	SDL_RenderPresent(Game::renderer);
}