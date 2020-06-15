#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "Vector2D.h"
#include "Matrix.h"
/*! \brief Uses RK4 integration. Which can be used to simulate gravity.
I can then apply acceleration to make stuff move.*/
class Moveable
{
private:
	Matrix matrixCalculator;
protected:
	Matrix points;
	Vector2D pos, vel ,acc;
	Vector2D rotationalVel,rotationalAcc;
	float torque;
	float drag, mass, elasticity, friction, density;
	void intergrate(float time);//!< Intergrates using rk4
	float area, inverseMass;
public:
	Moveable();
	~Moveable();
	void setAcc(Vector2D nAcc);//!< sets acceleration
	void setVel(Vector2D nVel);//!< Sets Velocity
	void setAngularAcc(Vector2D nAngularAcc){rotationalAcc = nAngularAcc;};
	void setAngularVel(Vector2D nAngularVel){rotationalVel = nAngularVel;};//!< Sets Velocity
	void setPos(Vector2D nPos);//!< sets Position
	void setInverseMass(float m){inverseMass = m;};
	void setCoeffient(float nDrag, float nDensity, float nElasticity, float nFriction);//!< Sets the coeffients
	Vector2D getPosition()const;//!< Returns Position
	Vector2D getVelocity()const;//!< Returns Velocity
	Vector2D getAccel()const;//!< Returns Acceleration
	Vector2D acceleration(Vector2D nPos, Vector2D nVel);//!< Calculates acceleration
	float getMass()const;//!<Calculates and Returns the Mass
	float getDrag()const;//!< Returns drag coefficent
	float getElasticity()const;//!< Returns Elasticity
	float getFriction()const;//!< Returns Friction
	float getDensity()const;//!< Returns Friction
	float getInverseMass()const{return inverseMass;};
	void rotate(double theta );
	void translate(double x, double y);
	void scale(double x, double y);
	//virtual void area()=0;
};
#endif