#include <SFML/Graphics.hpp>
#include "Matrix.h"
#include <iostream>
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Arc.h"
#include "Line.h"
#include "Dot.h"
#include "Moveable.h"
#include "Collision.h"
#include "Manifold.h"
#include "Randomiser.h"

enum Colour{red,green,magenta,yellow,blue,cyan,white};

int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Shapes",  sf::Style::Default, settings);
	sf::Clock clock;
	float size = 500;
	float refreshRate = 0.0083f;

	Randomiser rand;

	int balls  = rand.getRandBetween(5,15);
	std::vector<Circle> circle;
	circle.resize(balls);
	for(int i=0;i<balls;++i)
	{
		int c = rand.getRandBetween(0,6);
		float x = rand.getRandBetween(130.f,870.f);
		float y = rand.getRandBetween(130.f,570.f);
		float r = rand.getRandBetween(10.f,30.f);
		circle[i] = Circle(x,y,r,20);
		circle[i].setCoeffient(0.f,1.f,1.0f,0.0f);
		circle[i].setAcc(Vector2D(0.0f, 20.0f));
		circle[i].setInverseMass(1/circle[i].getMass());
		switch(c)
		{
		case red:
			circle[i].setColour(sf::Color::Red);
			break;
		case green:
			circle[i].setColour(sf::Color::Green);
			break;
		case magenta:
			circle[i].setColour(sf::Color::Magenta);
			break;
		case yellow:
			circle[i].setColour(sf::Color::Yellow);
			break;
		case blue:
			circle[i].setColour(sf::Color::Blue);
			break;
		case cyan:
			circle[i].setColour(sf::Color::Cyan);
			break;
		case white:
			circle[i].setColour(sf::Color::White);
			break;
		}
	}

	Line line[4];
	line[0] = Line(100,600,900,600);
	line[1] = Line(900,600,900,100);
	line[2] = Line(900,100,100,100);
	line[3] = Line(100,100,100,600);
	for(int i=0;i<4;++i)
	{
		line[i].setColour(sf::Color::Cyan);
		line[i].setInverseMass(0);
		line[i].setCoeffient(0.f,1.f,1.f,0.0f);
	}
	std::vector<Shape*> shapes;
	shapes.resize(balls);
	//std::vector<Circle>::iterator it;
	for(int i=0;i<balls;++i)
	{
		shapes[i]=&circle[i];
		shapes[i]->circle = &circle[i];
	}

	Shape* lines[4];
	for(int i=0; i<4;++i)
	{
		lines[i] = &line[i];
		lines[i]->line = &line[i];
	}


	Collision collision;

	//!Run the loop
	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if((float)clock.getElapsedTime().asSeconds() > refreshRate)
		{	
			float y = (lines[0]->getPosition().getY() + lines[2]->getPosition().getY()) /2;
			float x = (lines[3]->getPosition().getX() + lines[1]->getPosition().getX()) /2;


			for(int i=0;i<4;++i)
			{
				for(int j=0;j<balls;++j)
				{
					for(int k=0;k<balls;++k)
					{
						for(int t=0; t<15;++t)
						{
							if(collision.CircleToCircle(*shapes[j]->circle,*shapes[k]->circle))
							{
								collision.ApplyImpulse(*shapes[j],*shapes[k]);
							}
						}
					}
					//!Roatates all the lines.
					lines[i]->line->updatePosition();
					lines[i]->translate(-x,-y);
					lines[i]->rotate(0.001);
					lines[i]->translate(x,y);
					//Checks Collision between lines and circles
					for(int t=0; t<15;++t)
					{
						if(collision.CircleToLine(*shapes[j]->circle,*lines[i]->line))
						{
							collision.ApplyImpulse(*shapes[j],*lines[i]);//!< Applies impulse to circles.
						}
					}

					shapes[j]->intergrate(refreshRate);//Updates position of the circles
				}

			}
			clock.restart();
		}
		
		for(int i=0; i<4;++i)
		{
			window.draw(*lines[i]);// Draws all the lines
		}
		
		for(int i=0; i<balls;++i)
		{
			window.draw(*shapes[i]);//Draws all circles
		}
		window.display();
	}





	return 0;
}