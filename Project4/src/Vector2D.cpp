/*!
@UI.cpp
*/
#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D()
{
	x = 0.f;
	y = 0.f;
}
Vector2D::~Vector2D()
{
}
Vector2D::Vector2D(float nx, float ny)
{
	x = nx;
	y = ny;
}
Vector2D Vector2D::add(const Vector2D &other) const
{
	return Vector2D(x + other.x, y + other.y);
}
Vector2D Vector2D::subtract(const Vector2D &other) const
{
	return Vector2D(x - other.x, y - other.y);
}
Vector2D Vector2D::scalar(float scalar) const
{
	return Vector2D(x*scalar,y*scalar);
}
Vector2D Vector2D::minMax(const Vector2D &a, const Vector2D &b) const
{
	float rX = 0.f;
	float rY = 0.f;

	if(a.getX() >= 0)
	{
		rX = std::min(a.getX(), b.getX());
	}
	else if(a.getX() < 0)
	{
		rX = std::max(a.getX(), -b.getX());
	}
	if(a.getY() >= 0)
	{
		rY = std::min(a.getY(), b.getY());
	}
	else if(a.getY() < 0)
	{
		rY = std::max(a.getY(), -b.getY());
	}
	return Vector2D(rX,rY);
}
float Vector2D::dotProduct(const Vector2D &other) const
{
	return x * other.x + y * other.y;
}
float Vector2D::crossProduct(const Vector2D &other) const
{
	return x*other.y - y*other.x;
}
float Vector2D::magnitude() const
{
	return std::sqrt(std::pow(x,2.f)+ std::pow(y,2.f));
}
float Vector2D::getX() const
{
	return x;
}
float Vector2D::getY() const
{
	return y;
}
Vector2D Vector2D::getUnitVector() const
{
	float mag = magnitude();
	return Vector2D (x/mag, y/mag);
}
void Vector2D::setXandY(float nx, float ny)
{
	x = nx;
	y = ny;
}
