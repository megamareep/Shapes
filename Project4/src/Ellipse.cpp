#include "Ellipse.h"


Ellipse::Ellipse(double centrePosX, double centrePosY, double newRadiusX, double newRadiusY, unsigned int newNumberOfPoints)
{
	
	numberOfPoints = newNumberOfPoints+1;
	if(numberOfPoints > 60)
		numberOfPoints = 60;
	points.setWidth(numberOfPoints);
	points.setHeight(4);
	points.createTable();
	radiusX = newRadiusX;
	radiusY = newRadiusY;
	double theta = 360.00000000/(numberOfPoints - 1);
	theta *= 3.14159265359 /180 ;
	for(int i = 0; i < numberOfPoints ; i++)
	{
		points.setElement(centrePosX + cos(theta*i) * radiusX, i,0);
		points.setElement(centrePosY + sin(theta*i) * radiusY, i,1);
		points.setElement(1,i,3);
	}
	points.setElement(points.getElement(0,0), numberOfPoints-1,0);
	points.setElement(points.getElement(0,1), numberOfPoints-1,1);


}

double  Ellipse::getPosX(double PosX)
{
	return points.getElement(PosX,0);
}

double  Ellipse::getPosY(double PosY)
{
	return points.getElement(PosY,1);
}