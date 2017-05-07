#include "stdafx.h"
#include "Square.h"
#include "GL\glut.h"

Square::Square()
	: Rectangle()
{

}

Square::Square(Point _p, int _s)
	: Rectangle(_p, _s, _s)
{

}

Square::Square(int _px, int _py, int _s)
	: Rectangle(_px, _py, _s, _s)
{

}

void Square::Display() const
{
	glColor4d(red, green, blue, alpha);
	Rectangle::Display();
}

void Square::setMidpoint(const Point _m)
{
	Rectangle::setMidpoint(_m);
}

void Square::setMidpoint(const int _mx, const int _my)
{
	Rectangle::setMidpoint(_mx, _my);
}

void Square::setSize(const int _s)
{
	Rectangle::setHeight(_s);
	Rectangle::setWidth(_s);
}

int Square::getSize() const
{
	return Rectangle::getHeight();
}

const Point& Square::getMidpoint() const
{
	return Rectangle::getMidpoint();
}

float Square::distance(const Square& _s) const
{
	return Rectangle::distance(_s);
}

bool Square::isOverlapping(const Square& _s) const
{
	return Rectangle::isOverlapping(_s);
}