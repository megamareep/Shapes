#include "Rectangle.h"



Rectangle::Rectangle(double width,double height, double xPos, double yPos)
{
	numberOfPoints = 5;
	points.setWidth(numberOfPoints);
	points.setHeight(4);
	points.createTable();
	for(int i = 0; i < numberOfPoints; i++)
	{
		points.setElement(1,i,3);
	}
	points.setElement(xPos, 0,0);
	points.setElement(yPos, 0,1);
	points.setElement(xPos + width, 1,0);
	points.setElement(yPos, 1,1);
	points.setElement(xPos + width, 2,0);
	points.setElement(yPos + height, 2,1);
	points.setElement(xPos, 3,0);
	points.setElement(yPos + height, 3,1);
	points.setElement(xPos, 4,0);
	points.setElement(yPos, 4,1);

}
double Rectangle::getParamsX(double xPos)const
{
	return points.getElement(xPos,0);
	

}

double Rectangle::getParamsY(double yPos)const
{
	return points.getElement(yPos,1);
	

}