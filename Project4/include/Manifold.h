#ifndef MANIFOLD_H
#define MANIFOLD_H

#include "Vector2D.h"
#include "Collision.h"
#include "Shape.h"
#include <algorithm> 
#define REFRESH_RATE 0.00833f
/*! \brief Applies impulse and position correction of an Circle to Box */ 
class Manifold
{
private:
	float slop, percentCorrection;//!< Used for position correction
	float penetrationDepth;//!< Depth of penetration
	Vector2D normal;//!<Normal of A to B
	Vector2D contact;//!< Point of Contacts
public:
	Manifold();//!< Default constructor
	~Manifold();
	void Initialize(Shape &a, Shape &b, float &d, Vector2D &nNormal, Vector2D &nContact);  //!< Precalculations for impulse solving
    void ApplyImpulse(Shape &a, Shape &b);   //!< Solve impulse and apply
};
#endif