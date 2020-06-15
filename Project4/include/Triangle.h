#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "Shape.h"

class Triangle: public Shape
{

public:

	Triangle(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2, double xPosition3, double yPosition3);

	void setParams(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2, double xPosition3, double yPosition3);

};


#endif