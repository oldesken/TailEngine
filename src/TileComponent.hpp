#pragma once

#include<iostream>
#include<random>

#include "TailEngine/Entity/Component.hpp"
#include "TailEngine/DefaultComponents/PositionComponent.hpp"
#include "TailEngine/Graphics/SpriteComponent.hpp"
#include "TailEngine/Math/Vector2f.hpp"

class TileComponent : public Component
{
public:
	PositionComponent* position;
	SpriteComponent* sprite;

	SDL_Rect destRect;
	SDL_Rect srcRect;
	int tileId;
	char* path;

	TileComponent() = default;

	TileComponent(float x, float y, float w, float h, int id)
	{
		destRect.x = x;
		destRect.y = y;
		destRect.w = w;
		destRect.h = h;

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 32;
		srcRect.h = 32;

		tileId = id;
	}

	void init() override
	{
		entity-> addComponent<PositionComponent>(destRect.x, destRect.y);

		switch(tileId)
		{
			case 0:
			{
				int initial = std::rand() % 5;
				srcRect.x = 32 * initial;
				entity-> addComponent<SpriteComponent>("res/gfx/CalmWater.png", srcRect, destRect, 5, 1000);
				break;
			}
			case 1:
			{
				int initial = std::rand() % 5;
				srcRect.x = 32 * initial;
				entity-> addComponent<SpriteComponent>("res/gfx/TurbulentWater.png", srcRect, destRect, 5, 1000);
				break;
			}
			case 2:
			{
				int initial = std::rand() % 5;
				srcRect.x = 32 * initial;
				entity-> addComponent<SpriteComponent>("res/gfx/Sand.png", srcRect, destRect);
				break;
			}
			case 3:
			{
				int initial = std::rand() % 5;
				srcRect.x = 32 * initial;
				entity-> addComponent<SpriteComponent>("res/gfx/Dirt.png", srcRect, destRect);
				break;
			}
			

		default:
			break;
		}
	}
};