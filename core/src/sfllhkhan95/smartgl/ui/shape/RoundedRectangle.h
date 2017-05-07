#pragma once
#include "Rectangle.h"
class RoundedRectangle :
	public Rectangle
{
public:
	RoundedRectangle();
	RoundedRectangle(Point, int, int);
	RoundedRectangle(int, int, int, int);

	void Display() const;
};

