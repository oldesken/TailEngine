#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "TailEngine/Entity/ECS.hpp"
#include "TailEngine/DefaultComponents/PositionComponent.hpp"
#include "TextureManager.hpp"

class SpriteComponent : public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path, SDL_Rect src, SDL_Rect dest);
	SpriteComponent(const char* path, SDL_Rect src, SDL_Rect dest, int nFrame, int mSpeed);

	void init() override;
	void update() override;
	void draw() override;

private:
	PositionComponent* positionComponent;
	SDL_Texture *texture;
	SDL_Rect srcRect;
	SDL_Rect destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;
};