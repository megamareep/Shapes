#ifndef LINE_H
#define LINE_H


#include "Shape.h"

class Line: public Shape
{
private:
	Vector2D startP, endP;
public:
	Line()
	{
		area = 102000.f;
		colour = sf::Color::White;
	};
	~Line(){};
	Line(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2);

	void setParams(double xPosition1, double yPosition1, double xPosition2, 
		double yPosition2);
	void setParams(Vector2D nStart, Vector2D nEnd);
	float lineOrigin();
	Vector2D lineNormal();
	void intergrate(float time){Moveable::intergrate(time);};
	void updatePosition();
	Vector2D getStart()const{return startP;};
	Vector2D getEnd()const{return endP;};
};


#endif