#include "SpriteComponent.hpp"
#include "TextureManager.hpp"

// Ta errado mas funciona
TextureManager manager;

SpriteComponent::SpriteComponent(const char* path, SDL_Rect src, SDL_Rect dest)
{
	texture = manager.loadTexture(path);

	srcRect.x = src.x;
	srcRect.y = src.y;
	srcRect.w = src.w;
	srcRect.h = src.h;
	destRect.w = dest.w;
	destRect.h = dest.h;
}

SpriteComponent::SpriteComponent(const char* path, SDL_Rect src, SDL_Rect dest, int nFrame, int mSpeed)
{
	animated = true;
	frames = nFrame;
	speed = mSpeed;

	texture = manager.loadTexture(path);

	srcRect.x = src.x;
	srcRect.y = src.y;
	srcRect.w = src.w;
	srcRect.h = src.h;
	destRect.w = dest.w;
	destRect.h = dest.h;
}

void SpriteComponent::init()
{
	positionComponent = &entity->getComponent<PositionComponent>();
}

void SpriteComponent::update()
{
	if (animated)
	{
		srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
	}

	destRect.x = positionComponent->position.x;
	destRect.y = positionComponent->position.y;
}

void SpriteComponent::draw()
{
	manager.drawTexture(texture, srcRect, destRect);
}