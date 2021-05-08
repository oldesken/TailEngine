#include <SDL2/SDL.h>
#include <SDL2/SDl_image.h>

#include "Entity.hpp"

Entity::Entity()
{
}

void Entity::update()
{
	for (auto& c : components) c->update();
}

void Entity::draw()
{
	for (auto& c : components) c->draw();
}

bool Entity::isActive()
{
	return active;
}

void Entity::destroy()
{
	active = false;
}