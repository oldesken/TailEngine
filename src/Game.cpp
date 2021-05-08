#include<iostream>
#include<random>

#include "TailEngine/Game.hpp"
#include "TailEngine/Entity/ECS.hpp"
#include "TailEngine/Math/Vector2f.hpp"
#include "TileComponent.hpp"
#include "Cave.hpp"


SDL_Renderer* Game::renderer = nullptr;
EntityManager entityManager;

SDL_Event Game::event;
auto& tileMap(entityManager.addEntity());


Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen) {flags = SDL_WINDOW_FULLSCREEN;}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsistems Initialized!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(window) {std::cout << "Window created!" << std::endl;}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer) {std::cout << "Render Created!" << std::endl;}

		isRunning = true;

	} else {isRunning = false;}

	
	// Temporario
	int** cave = generateCave(27, 27, 56, 4, 5);

	for (int i = 1; i < 26; i ++)
	{
		for (int j = 1; j < 26; j ++)
		{
			if (cave[i][j] == 0) tileMap.addComponent<TileComponent>(j * 32 - 32,i * 32 - 32, 32, 32, 2);
			if (cave[i][j] == 1) tileMap.addComponent<TileComponent>(j * 32 - 32,i * 32 - 32, 32, 32, 0);
		}
	}

	
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
	}
}

void Game::update()
{
	entityManager.update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	entityManager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}