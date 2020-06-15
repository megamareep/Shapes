#ifndef COLLISION_H
#define COLLISION_H


#include "Vector2D.h"
#include "Line.h"
#include "Circle.h"
#include "Square.h"
#include "Manifold.h"

/*! \brief Checks collisions*/
class Collision
{
private:
	float penetrationDepth;//!< Depth of penetration
	Vector2D normal2;//!< Normal
	Vector2D contact;
	float distance;//!< Penetration depth in circle to aabb
public:
	Collision();
	~Collision();
	bool CircleToCircle(Shape &a, Shape &b );//!< Circle to circle detection
	bool CircleToLine(Shape &a, Shape &b);//!< Circle to line detection
	void ApplyImpulse(Shape &a, Shape &b);


	//bool AABBtoAABB(Box &a, Box &b,Vector2D &Nnormal);//!<Box to Box collision detection
	bool CircleToAABB(Circle &a, Square& b, bool &hitFloor, bool &hitSide, bool &hitUnder);//!< Circle to aabb detection
	//void applyAABBtoAABBimpulse(Box &a, Box &b);//!< Applies Impulse AABB to AABB
//	void applyCtoAABBimpulse(Circle &a, Box &b);//!< Applies Impulse Circle to AABB
};
#endif