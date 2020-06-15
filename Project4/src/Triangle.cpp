#include "Triangle.h"


Triangle::Triangle(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2, double xPosition3, double yPosition3)
{
	numberOfPoints = 4;
	points.setHeight(4);
	points.setWidth(4);
	points.createTable();
	for(int i = 0; i < 4; i++)
	{
		points.setElement(1,i,3);
	}
	points.setElement(xPosition1, 0,0);
	points.setElement(yPosition1, 0,1);
	points.setElement(xPosition2, 1,0);
	points.setElement(yPosition2, 1,1);
	points.setElement(xPosition3, 2,0);
	points.setElement(yPosition3, 2,1);
	points.setElement(xPosition1, 3,0);
	points.setElement(yPosition1, 3,1);

}


void Triangle::setParams(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2, double xPosition3, double yPosition3)
{
	points.setElement(xPosition1, 0,0);
	points.setElement(yPosition1, 0,1);
	points.setElement(xPosition2, 1,0);
	points.setElement(yPosition2, 1,1);
	points.setElement(xPosition3, 2,0);
	points.setElement(yPosition3, 2,1);
	points.setElement(xPosition1, 3,0);
	points.setElement(yPosition1, 3,1);

}