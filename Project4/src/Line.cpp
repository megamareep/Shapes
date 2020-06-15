#include "Line.h"



Line::Line(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2)
{
	area = 102000.f;
	colour = sf::Color::White;
	startP.setXandY(xPosition1,yPosition1);
	endP.setXandY(xPosition2,yPosition2);
	numberOfPoints = 2;
	points.setWidth(numberOfPoints);
	points.setHeight(4);
	points.createTable();
	for(int i = 0; i < numberOfPoints; i++)
	{
		points.setElement(1,i,3);
	}
	points.setElement(xPosition1, 0,0);
	points.setElement(yPosition1, 0,1);
	points.setElement(xPosition2, 1,0);
	points.setElement(yPosition2, 1,1);
	float centrePosX = (xPosition2 + xPosition1) /2;
	float centrePosY = (yPosition2 + yPosition1) /2;
	pos.setXandY(centrePosX,centrePosY);
}
void Line::updatePosition()
{
	startP.setXandY(points.getElement(0,0),points.getElement(0,1));
	endP.setXandY(points.getElement(1,0),points.getElement(1,1));
	float centrePosX = (startP.getX() + endP.getX()) /2;
	float centrePosY = (startP.getY()+ endP.getY()) /2;
	pos.setXandY(centrePosX,centrePosY);
}
void Line::setParams(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2)
{
	startP.setXandY(xPosition1,yPosition1);
	endP.setXandY(xPosition2,yPosition2);
	points.setElement(xPosition1, 0,0);
	points.setElement(yPosition1, 0,1);
	points.setElement(xPosition2, 1,0);
	points.setElement(yPosition2, 1,1);
	float centrePosX = (xPosition2 + xPosition1) /2;
	float centrePosY = (yPosition2 + yPosition1) /2;
	pos.setXandY(centrePosX,centrePosY);
}
void Line::setParams(Vector2D nStart, Vector2D nEnd)
{
	startP = nStart;
	endP = nEnd;
	points.setElement(nStart.getX(), 0,0);
	points.setElement(nStart.getY(), 0,1);
	points.setElement(nEnd.getX(), 1,0);
	points.setElement(nEnd.getY(), 1,1);
	float centrePosX = (nStart.getX() + nEnd.getX()) /2;
	float centrePosY = (nStart.getY() + nEnd.getY()) /2;
	pos.setXandY(centrePosX,centrePosY);
}
float Line::lineOrigin()
{
	return ((startP.getX() - endP.getX()) * startP.getY() + (endP.getY() - startP.getY()) * startP.getX());//!< Finds the origin of the line.
}
Vector2D Line::lineNormal()
{
	return Vector2D(startP.getY()-endP.getY(), endP.getX() - startP.getX());//!< Finds the normal of the line.;
}