#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse: public Shape
{
private:
	double radiusX;
	double radiusY;
	
public:
	Ellipse(double centrePosX, double centrePosY, double newRadiusX, double newRadiusY, unsigned int newNumberOfPoints);
	double getPosX(double PosX);
	double getPosY(double PosY);
};


#endif