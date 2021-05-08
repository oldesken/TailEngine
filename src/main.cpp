// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <iostream>
// #include <vector>

// #include "TailEngine/Window/Window.hpp"
// #include "TailEngine/Utils/Utils.hpp"
// #include "TailEngine/Entity/EntityManager.hpp"
// #include "TailEngine/DefaultComponents/PositionComponent.hpp"
// #include "TailEngine/Graphics/TextureManager.hpp"
// #include "TailEngine/Graphics/SpriteComponent.hpp"

// int main(int argc, char* args[])
// {
// 	if (SDL_Init(SDL_INIT_VIDEO) > 0)
// 		std::cout << "SDL_Init Failed. SDL_ERROR: " << SDL_GetError() << std::endl;

// 	if (!(IMG_Init(IMG_INIT_PNG)))
// 		std::cout << "IMG_Init failed. Error: " << SDL_GetError() << std::endl;

// 	Window mainWindow("Game v0.0", 1028, 512);
// 	TextureManager layer1(mainWindow.window);

// 	EntityManager entityManager;
// 	auto& newPlayer(entityManager.addEntity());
// 	newPlayer.addComponent<PositionComponent>();
// 	newPlayer.addComponent<SpriteComponent>("res/gfx/ground_grass_1.png", layer1);


// 	// std::vector<Entity> entities = {Entity(Vector2f(0, 0), grassTexture),
// 	// 								Entity(Vector2f(30, 0), grassTexture),
// 	// 								Entity(Vector2f(60, 0), grassTexture)};
// 	// {
// 	// 	Entity plataformWilson(Vector2f(90, 0), grassTexture);

// 	// 	entities.push_back(plataformWilson);
// 	// }

// 	bool gameRunning = true;

// 	SDL_Event event;

// 	const float timeStep = 0.01f;
// 	float accumulator = 0.0f;
// 	float currentTime = utils::hireTimeInSeconds();

// 	while (gameRunning)
// 	{
// 		int startTicks = SDL_GetTicks();

// 		float newTime = utils::hireTimeInSeconds();
// 		float frameTime = newTime - currentTime;

// 		currentTime = newTime;

// 		accumulator += frameTime;
// 		while (accumulator >= timeStep){
// 			while (SDL_PollEvent(&event))
// 			{
// 				if (event.type == SDL_QUIT)
// 					gameRunning = false;
// 			}
// 			accumulator -= timeStep;
// 		}

// 		const float alpha = accumulator / timeStep;

// 		layer1.clear();

// 		// for (Entity& e : entities)
// 		// {
// 		// 	Vector2f translation = Vector2f(.5f, .5f);
// 		// 	translation *= 4;
// 		// 	std::cout << e.getPosition() << std::endl;
// 		// 	e.translate(translation);
// 		// 	window.render(e);
// 		// }


// 		entityManager.update();
// 		entityManager.draw();
// 		newPlayer.getComponent<PositionComponent>().position += Vector2f(0.1f, 0.1f);
// 		std::cout << 1/frameTime << std::endl;

// 		layer1.display();

// 		int frameTicks = SDL_GetTicks() - startTicks;

// 		if (frameTicks < 1000 / mainWindow.getRefreshRate())
// 			SDL_Delay(1000 / mainWindow.getRefreshRate() - frameTicks);

// 	}

// 	mainWindow.cleanUp();
// 	SDL_Quit();

// 	return 0;
// }

#include <iostream>

#include "TailEngine/Game.hpp"

Game* game = nullptr;

int main(int argc, char* args[])
{
	const int FPS = 60;
	const int frameDelay = 1000/FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("TailEngine V0.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, true);

	while (game -> running())
	{

		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}