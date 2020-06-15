#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <SFML/Graphics.hpp>
#include <algorithm> 

/*! \brief Allows me to do calculations for the vectors. */
class Vector2D: sf::Vector2f
{
private:

public:
	Vector2D();
	~Vector2D();
	Vector2D(float nx, float ny);
	Vector2D add(const Vector2D &other) const;//!< Adds two vectors
	Vector2D subtract(const Vector2D &other) const;//!< Subtracts two vectors
	Vector2D scalar(float scalar) const;//!< Multiplys a Vector by a scalar
	Vector2D minMax(const Vector2D &a, const Vector2D &b) const;//!< Clamps the minMax values used in collision detection.
	float dotProduct(const Vector2D &other) const;//<! Returns the dotproduct between two vectors.
	float crossProduct(const Vector2D &other) const;//!< Returns the crossProduct between two vectors.
	float magnitude() const;//!< Finds the magnitude of a vector
	float getX()const;//!< Returns X value
	float getY()const;//!< Returns Y value
	void setXandY(float nx, float ny);//!< Sets X and Y value
	Vector2D getUnitVector() const;//!< Returns the Vector as a unit vector. Normalises.
};


#endif