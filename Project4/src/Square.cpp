#include "Square.h"



Square::Square(double size, double xPos, double yPos)
{
	mSize = size;
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
	points.setElement(xPos + size, 1,0);
	points.setElement(yPos, 1,1);
	points.setElement(xPos + size, 2,0);
	points.setElement(yPos + size, 2,1);
	points.setElement(xPos, 3,0);
	points.setElement(yPos + size, 3,1);
	points.setElement(xPos, 4,0);
	points.setElement(yPos, 4,1);

}
double Square::getParamsX(int xPos)const
{
	return points.getElement(xPos,0);
}

double Square::getParamsY(int yPos)const
{
	return points.getElement(yPos,1);
}

void Square::intergrate(float time)
{
	double theta = 360.00000000/(numberOfPoints - 1);
	theta *= 3.14159265359 /180;
	Moveable::intergrate(time);
	float xPos = pos.getX();
	float yPos = pos.getY();

	for(int i = 0; i < numberOfPoints ; i++)
	{
		points.setElement(1,i,3);
	}
	points.setElement(xPos, 0,0);
	points.setElement(yPos, 0,1);
	points.setElement(xPos + mSize, 1,0);
	points.setElement(yPos, 1,1);
	points.setElement(xPos + mSize, 2,0);
	points.setElement(yPos + mSize, 2,1);
	points.setElement(xPos, 3,0);
	points.setElement(yPos + mSize, 3,1);
	points.setElement(xPos, 4,0);
	points.setElement(yPos, 4,1);

}
