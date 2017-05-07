#pragma once
#include "Rectangle.h"
#include "Point.h"

class Square : protected Rectangle
{
public:
	Square();
	Square(Point, int);
	Square(int, int, int);

	void Display() const;

	void setMidpoint(const Point);
	void setMidpoint(const int, const int);
	void setSize(const int);

	int getSize() const;
	const Point& getMidpoint() const;

	float distance(const Square&) const;
	bool isOverlapping(const Square&) const;
};