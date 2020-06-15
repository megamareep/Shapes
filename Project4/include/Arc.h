#ifndef ARC_H
#define ARC_H

#include "Shape.h"

class Arc: public Shape
{
private:
	double radiusX;
	double radiusY;
	double startAngle;
	double endAngle;
public:
	Arc(double centrePosX, double centrePosY,double newStartAngle,double newEndAngle, double newRadiusX, double newRadiusY, unsigned int newNumberOfPoints);
	double getPosX(double PosX);
	double getPosY(double PosY);
};


#endif