#include "Vector2f.hpp"

Vector2f& Vector2f::Add(const Vector2f& vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2f& Vector2f::Subtract(const Vector2f& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2f& Vector2f::Multiply(const float scalar)
{
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}

Vector2f& Vector2f::Divide(const float scalar)
{
	this->x /= scalar;
	this->y /= scalar;

	return *this;
}

Vector2f& operator+(Vector2f& v1, const Vector2f& v2)
{
	return v1.Add(v2);
}

Vector2f& operator-(Vector2f& v1, const Vector2f& v2)
{
	return v1.Subtract(v2);
}

Vector2f& operator*(Vector2f& v1, const float scalar)
{
	return v1.Multiply(scalar);
}

Vector2f& operator/(Vector2f& v1, const float scalar)
{
	return v1.Divide(scalar);
}

Vector2f& Vector2f::operator+=(const Vector2f& vec)
{
	return this->Add(vec);
}

Vector2f& Vector2f::operator-=(const Vector2f& vec)
{
	return this->Subtract(vec);
}

Vector2f& Vector2f::operator*=(const float scalar)
{
	return this->Multiply(scalar);
}

Vector2f& Vector2f::operator/=(const float scalar)
{
	return this->Divide(scalar);
}

std::ostream& operator<<(std::ostream& stream, const Vector2f& vec)
{
	stream << "(" << vec.x << ", " << vec.y << ")";
	return stream;
}