#pragma once 

#include "TailEngine/Game.hpp" 
#include "TailEngine/Entity/ECS.hpp"

class KeyboardController : public Component
{
public:
	void init() override
	{

	}

	void update() override
	{
		if(Game::event.type == SDL_KEYDOWN)
		{
			switch(Game::event.key.keysim.sym)
			{
				
			}
		}

		if(Game::event.type == SDL_KEYUP )
	}
}