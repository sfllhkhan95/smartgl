#pragma once
#include "Shape.h"

class Circle :
	public Shape
{
public:
	Circle();
	Circle(Point, int);
	Circle(int, int, int);

	void Display() const;

	void setRadius(const int);
	int getRadius() const;

private:
	int radius;
};

