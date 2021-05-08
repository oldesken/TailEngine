#pragma once

#include <iostream>

class Vector2f
{
public:
	Vector2f()
	:x(0.0f), y(0.0f)
	{}

	Vector2f(float p_x, float p_y)
	:x(p_x), y(p_y)
	{}

	Vector2f& Add(const Vector2f& vec);
	Vector2f& Subtract(const Vector2f& vec);
	Vector2f& Multiply(const float scalar);
	Vector2f& Divide(const float scalar);

	friend Vector2f& operator+(Vector2f& v1, const Vector2f& v2);
	friend Vector2f& operator-(Vector2f& v1, const Vector2f& v2);
	friend Vector2f& operator*(Vector2f& v1, const float scalar);
	friend Vector2f& operator/(Vector2f& v1, const float scalar);

	Vector2f& operator+=(const Vector2f& vec);
	Vector2f& operator-=(const Vector2f& vec);
	Vector2f& operator*=(const float scalar);
	Vector2f& operator/=(const float scalar);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vec);

	float x, y;
};