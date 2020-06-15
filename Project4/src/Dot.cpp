#include "Dot.h"
#include <iostream>


Dot::Dot(double xPosition, double yPosition)
{
	numberOfPoints = 1;
	points.setWidth(numberOfPoints);
	points.setHeight(4);
	points.createTable();
	
	for(int i = 0; i < numberOfPoints; i++)
	{
		points.setElement(1,i,3);
	}
	points.setElement(xPosition, 0,0);
	points.setElement(yPosition, 0,1);

}


void Dot::setParams(double xPosition, double yPosition)
{
	points.setElement(xPosition, 0,0);
	points.setElement(yPosition, 0,1);

}
void Dot::getParams(double& xPosition , double& yPosition )
{
	xPosition = points.getElement(0,0);
	yPosition = points.getElement(0,1);

}