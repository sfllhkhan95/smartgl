#include "stdafx.h"
#include "Rectangle.h"
#include "GL\glut.h"
#include <cmath>

Rectangle::Rectangle()
	: Shape(Point()), width(0), height(0)
{

}

Rectangle::Rectangle(Point _m, int _w, int _h)
	: Shape(_m), width(_w), height(_h)
{

}

Rectangle::Rectangle(int _mx, int _my, int _w, int _h)
	: Shape(Point(_mx, _my)), width(_w), height(_h)
{

}

void Rectangle::Display() const
{
	glColor4d(red, green, blue, alpha);

	int x = getMidpoint().getX();
	int y = getMidpoint().getY();

	glBegin(GL_POLYGON);
	glVertex2i(x - width / 2, y - height / 2);
	glVertex2i(x - width / 2, y + height / 2);
	glVertex2i(x + width / 2, y + height / 2);
	glVertex2i(x + width / 2, y - height / 2);
	glEnd();
}

void Rectangle::setWidth(const int _w)
{
	width = _w;
}

void Rectangle::setHeight(const int _h)
{
	height = _h;
}

int Rectangle::getWidth() const
{
	return width;
}

int Rectangle::getHeight() const
{
	return height;
}

float Rectangle::distance(const Rectangle& _r) const
{
	return getMidpoint().distance(_r.getMidpoint());
}

bool Rectangle::isOverlapping(const Rectangle& _r) const
{
	Point translation = getMidpoint() - _r.getMidpoint();

	if (abs(translation.getX()) < this->width + _r.width &&
		abs(translation.getY()) < this->height + _r.height)
		return true;

	else return false;
}

Point Rectangle::calculateMidpoint()
{
	return getMidpoint();
}