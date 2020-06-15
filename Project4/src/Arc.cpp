#include "Arc.h"

Arc::Arc(double centrePosX, double centrePosY,double newStartAngle, double newEndAngle, double newRadiusX, double newRadiusY, unsigned int newNumberOfPoints)
{
	
	numberOfPoints = newNumberOfPoints+1;
	if(numberOfPoints > 60)
		numberOfPoints = 60;
	points.setWidth(numberOfPoints);
	points.setHeight(4);
	points.createTable();
	radiusX = newRadiusX;
	radiusY = newRadiusY;
	startAngle = newStartAngle;
	endAngle = newEndAngle;
	double theta = (endAngle-startAngle)/ numberOfPoints;
	theta *= 3.14159265359 /180 ;
	for(int i = 0; i < numberOfPoints ; i++)
	{
		points.setElement(centrePosX + cos(theta*i) * radiusX, i,0);
		points.setElement(centrePosY + sin(theta*i) * radiusY, i,1);
		points.setElement(1,i,3);
	}

}

double  Arc::getPosX(double PosX)
{
	return points.getElement(PosX,0);
}

double  Arc::getPosY(double PosY)
{
	return points.getElement(PosY,1);
}