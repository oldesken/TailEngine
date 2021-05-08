#pragma once 

#include "ECS.hpp"

class EntityManager
{
public:
	
	void update();
	void draw();
	void refresh();

	Entity& addEntity();
private:
	std::vector<std::unique_ptr<Entity>> entities;	
};