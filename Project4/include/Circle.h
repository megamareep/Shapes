#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape
{
private:
	double radius;
	double centreX;
	double centreY;
	
public:
	Circle(){colour = sf::Color::White;};
	~Circle(){};
	Circle(double centrePosX, double centrePosY, double newRadius, unsigned int newNumberOfPoints);
	void setCentre(double newCentreX, double newCentreY);
	void intergrate(float time);
	double getRadius()const{return radius;};
};
#endif