#ifndef SHAPE_H
#define SHAPE_H

#include <SFML\Graphics.hpp>
#include "Matrix.h"
#include "Vector2D.h"
#include "Moveable.h"
class Line;
class Circle;
class Square;
class Shape: public sf::Drawable, public Moveable
{
protected:
	sf::Color colour;
	//Matrix points;
	unsigned int numberOfPoints;
public:
	Shape();
	~Shape(){
			
	};
	void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	void setColour(sf::Color c) { colour = c;};

	Square* square = nullptr;
	Circle* circle = nullptr;
	Line* line = nullptr;
	virtual void intergrate(float time)=0;
};



#endif