#pragma once

#include "TailEngine/Entity/ECS.hpp"
#include "TailEngine/Math/Vector2f.hpp"

class PositionComponent : public Component
{
public:

	Vector2f position;

	PositionComponent()
	:position(Vector2f(0.f, 0.f))
	{};

	PositionComponent(float p_x, float p_y)
	:position(Vector2f(p_x, p_y))
	{};

	void init() override
	{	}

	void update() override
	{	}

	void draw() override
	{	}

private:
	
};