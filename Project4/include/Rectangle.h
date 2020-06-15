#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "Shape.h"

class Rectangle: public Shape
{

private:
	double size1;
public:
	Rectangle(double width,double height, double xPos, double yPos);
	double getParamsX(double xPos)const;
	double getParamsY(double yPos)const;
};

#endif