#include "stdafx.h"
#include "RoundedRectangle.h"
#include "GL\glut.h"

RoundedRectangle::RoundedRectangle()
	: Rectangle()
{

}

RoundedRectangle::RoundedRectangle(Point _m, int _w, int _h)
	: Rectangle(_m, _w, _h)
{

}

RoundedRectangle::RoundedRectangle(int _mx, int _my, int _w, int _h)
	: Rectangle(_mx, _my, _w, _h)
{

}

void RoundedRectangle::Display() const
{
	glColor4d(red, green, blue, alpha);

	float _i = 0.1f * getHeight();

	float x = getMidpoint().getX() - getWidth() / 2;
	float y = getMidpoint().getY() - getHeight() / 2;

	glBegin(GL_POLYGON);
	glVertex2f(x + _i, y);
	glVertex2f(x + _i / 3.f, y + _i / 3.f);
	glVertex2f(x, y + _i);

	glVertex2f(x, y + getHeight() - _i);
	glVertex2f(x + _i / 3.f, y + getHeight() - _i / 3.f);
	glVertex2f(x + _i, y + getHeight());

	glVertex2f(x + getWidth() - _i, y + getHeight());
	glVertex2f(x + getWidth() - _i / 3, y + getHeight() - _i / 3);
	glVertex2f(x + getWidth(), y + getHeight() - _i);

	glVertex2f(x + getWidth(), y + _i);
	glVertex2f(x + getWidth() - _i / 3, y + _i / 3);
	glVertex2f(x + getWidth() - _i, y);
	glEnd();
}