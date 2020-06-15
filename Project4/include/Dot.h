#ifndef DOT_H
#define DOT_H


#include "Shape.h"

class Dot: public Shape
{
public:

	Dot(double xPosition, double yPosition);
	void setParams(double xPosition, double yPosition);
	void getParams(double& xPosition, double& yPosition);
};


#endif