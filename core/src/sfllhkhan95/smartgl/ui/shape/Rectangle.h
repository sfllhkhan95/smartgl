#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(Point, int, int);
	Rectangle(int, int, int, int);

	void Display() const;

	void setWidth(const int);
	void setHeight(const int);

	int getWidth() const;
	int getHeight() const;

	float distance(const Rectangle&) const;
	bool isOverlapping(const Rectangle&) const;
	
private:
	int width;
	int height;

	Point calculateMidpoint();
};