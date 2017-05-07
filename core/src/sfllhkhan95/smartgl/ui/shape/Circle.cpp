#include "stdafx.h"
#include "Circle.h"
#include "GL\glut.h"

Circle::Circle()
	: radius(0), Shape()
{
}

Circle::Circle(Point _m, int _r)
	: radius(_r), Shape(_m)
{
}

Circle::Circle(int _mx, int _my, int _r)
	: radius(_r), Shape(_mx, _my)
{

}

void Circle::Display() const
{
	glBegin(GL_POLYGON);

	glVertex2f(getMidpoint().getX(), getMidpoint().getY());

	for (int i = 0; i < 360; i++)
		glVertex2f(getMidpoint().getX() + radius * sin(i), getMidpoint().getY() + radius * cos(i));

	glEnd();
}

void Circle::setRadius(const int _r)
{
	radius = _r;
}

int Circle::getRadius() const
{
	return radius;
}