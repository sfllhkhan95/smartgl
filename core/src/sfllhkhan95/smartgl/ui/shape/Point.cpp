#include "stdafx.h"
#include "Point.h"
#include <cmath>


Point::Point(int _x, int _y)
	: x(_x), y(_y)
{
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(const int _x)
{
	x = _x;
}

void Point::setY(const int _y)
{
	y = _y;
}

void Point::set(const int _x, const int _y)
{
	x = _x;
	y = _y;
}

double Point::distance(const Point& p) const
{
	return sqrt(pow((double)x - p.x, 2) + pow((double)y - p.y, 2));
}

Point Point::operator - (const Point& _p) const
{
	int x = this->getX() - _p.getX();
	int y = this->getY() - _p.getY();

	return Point(x, y);
}

Point Point::operator + (const Point& _p) const
{
	int x = this->getX() + _p.getX();
	int y = this->getY() + _p.getY();

	return Point(x, y);
}

Point Point::operator * (const Point& _p) const
{
	int x = this->getX() * _p.getX();
	int y = this->getY() * _p.getY();

	return Point(x, y);
}

Point Point::operator / (const Point& _p) const
{
	int x = this->getX() / _p.getX();
	int y = this->getY() / _p.getY();

	return Point(x, y);
}

Point Point::operator % (const Point& _p) const
{
	int x = this->getX() % _p.getX();
	int y = this->getY() % _p.getY();

	return Point(x, y);
}

// Assignment addition
Point& Point::operator+=(const Point& T)
{
	this->x += T.x;
	this->y += T.y;

	return *this;
}

// Assignmnet subtraction
Point& Point::operator-=(const Point& T)
{
	this->x -= T.x;
	this->y -= T.y;

	return *this;
}

// Assignmnet multiplication
Point& Point::operator*=(const Point& T)
{
	this->x *= T.x;
	this->y *= T.y;

	return *this;
}

// Assignmnet division
Point& Point::operator/=(const Point& T)
{
	this->x /= T.x;
	this->y /= T.y;

	return *this;
}

// Assignmnet modulo
Point& Point::operator%=(const Point& T)
{
	this->x %= T.x;
	this->y %= T.y;

	return *this;
}

// Equality
bool Point::operator==(const Point& T) const{
	return (x == T.x && y == T.y);
}

// Greater than
bool Point::operator>(const Point& T) const{
	return (x > T.x && y > T.y);
}

// Greater than or equal to
bool Point::operator>=(const Point& T) const{
	return (x >= T.x && y >= T.y);
}

// Less than
bool Point::operator<(const Point& T) const{
	return (x < T.x && y < T.y);
}

// Less than or equal to
bool Point::operator<=(const Point& T) const{
	return (x <= T.x && y <= T.y);
}
