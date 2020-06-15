#include <SFML/Graphics.hpp>
#include "Shape.h"
#include <iostream>

Shape::Shape()
{
	
}

void Shape::draw(sf::RenderTarget &target, sf::RenderStates states)const
{
	//!Draw lines to form a shape.
	sf::Vertex line[2];
	for(unsigned int i = 0;i < numberOfPoints-1; i++)
	{
		line[0] = sf::Vertex(sf::Vector2f(points.getElement(i,0),points.getElement(i,1)),colour);
		line[1] = sf::Vertex(sf::Vector2f(points.getElement(i+1,0),points.getElement(i+1,1)),colour);

		target.draw(line,2,sf::Lines,states);
	}
	//!Draw a dot
	if(numberOfPoints == 1)
	{
	    sf::Vertex dot[1];
		dot[0] = sf::Vertex(sf::Vector2f(points.getElement(0,0),points.getElement(0,1)),sf::Color::Cyan);
		target.draw(dot,1,sf::Points);
	}
}


