#ifndef SQUARE_H
#define SQUARE_H


#include "Shape.h"

class Square: public Shape
{
public:
	Square(){colour = sf::Color::White;};
	Square(double size, double xPos, double yPos);
	double getParamsX(int xPos)const;
	double getParamsY(int yPos)const;
	double getSize() const { return mSize; }

	void intergrate(float time) override;
private:
	double mSize = 0.0;
};
#endif
