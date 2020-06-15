#include "Circle.h"
#include <cmath>

Circle::Circle(double centrePosX, double centrePosY, double newRadius, unsigned int newNumberOfPoints)
{
	colour = sf::Color::White;
	numberOfPoints = newNumberOfPoints+1;
	centreX = centrePosX;
	centreY = centrePosY;
	pos.setXandY(centrePosX,centrePosY);
	if(numberOfPoints > 60)
		numberOfPoints = 60;
	points.setWidth(numberOfPoints);
	points.setHeight(4);
	points.createTable();
	radius = newRadius;
	double theta = 360.00000000/(numberOfPoints - 1);
	theta *= 3.14159265359 /180 ;
	points.setElement(centreX , 0,0);
	points.setElement(centreY, 0,1);
	for(int i = 1; i < numberOfPoints ; i++)
	{
		points.setElement(centreX + std::cos(theta*i) * radius, i,0);
		points.setElement(centreY + std::sin(theta*i) * radius, i,1);
		points.setElement(1,i,3);
	}
	points.setElement(points.getElement(1,0), numberOfPoints-1,0);
	points.setElement(points.getElement(1,1), numberOfPoints-1,1);

	area = 3.14159265359 * (radius*radius);
}
void Circle::intergrate(float time)
{
	double theta = 360.00000000/(numberOfPoints - 1);
	theta *= 3.14159265359 /180;
	Moveable::intergrate(time);
	//points.setElement(pos.getX() , 0,0);
	//points.setElement(pos.getY(), 0,1);
	for(int i = 0; i < numberOfPoints ; i++)
	{
		points.setElement(pos.getX() + std::cos(theta*i) * radius, i,0);
		points.setElement(pos.getY() + std::sin(theta*i) * radius, i,1);
		points.setElement(1,i,3);
	}
	//points.setElement(points.getElement(1,0), numberOfPoints-1,0);
	//points.setElement(points.getElement(1,1), numberOfPoints-1,1);
}

void Circle::setCentre(double newCentreX, double newCentreY)
{
	centreX = newCentreX;
	centreY = newCentreY;
	pos.setXandY(newCentreX,newCentreY);
}