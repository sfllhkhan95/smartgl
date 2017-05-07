#include "stdafx.h"
#include "Line.h"
#include "GL\glut.h"

Line::Line()
	: beg(0, 0), end(0, 0)
{

}

Line::Line(Point _b, Point _e)
	: beg(_b), end(_e)
{

}

Line::Line(int _bx, int _by, int _ex, int _ey)
	: beg(_bx, _by), end(_ex, _ey)
{

}

void Line::Display() const
{
	glBegin(GL_LINES);
	glVertex2i(beg.getX(), beg.getY());
	glVertex2i(end.getX(), end.getY());
	glEnd();
}

void Line::setStart(const Point _b)
{
	beg = _b;
}

void Line::setStart(const int _bx, const int _by)
{
	beg = Point(_bx, _by);
}

void Line::setEnd(const Point _e)
{
	end = _e;
}

void Line::setEnd(const int _ex, const int _ey)
{
	end = Point(_ex, _ey);
}

const Point& Line::getStart() const
{
	return beg;
}

const Point& Line::getEnd() const
{
	return end;
}

float Line::gradient() const
{
	return (float)(end.getY() - beg.getY()) / (end.getX() - beg.getX());
}

float Line::intercept() const
{
	return (beg.getY() - gradient() * beg.getX());
}

bool Line::isParallel(const Line& _l) const
{
	return this->gradient() == _l.gradient() ?
		true : false;
}

bool Line::isPerpendicular(const Line& _l) const
{
	return this->gradient() / _l.gradient() == -1 ?
		true : false;
}

Point Line::calculateMidpoint()
{
	return Point((beg.getX() + end.getX()) / 2, (beg.getY() + end.getY()) / 2);
}