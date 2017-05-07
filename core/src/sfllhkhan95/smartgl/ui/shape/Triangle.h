#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle();
	Triangle(Point, Point, Point);
	Triangle(int, int, int, int, int, int);

	void Display() const;

	void setA(const Point);
	void setA(const int, const int);

	void setB(const Point);
	void setB(const int, const int);

	void setC(const Point);
	void setC(const int, const int);

	const Point& getA() const;
	const Point& getB() const;
	const Point& getC() const;
private:
	Point A;
	Point B;
	Point C;
public:
	Point calculateMidpoint();
};

