#pragma once
#include "Shape.h"

class Line : public Shape
{
public:
	Line();
	Line(Point, Point);
	Line(int, int, int, int);

	void Display() const;

	void setStart(const Point);
	void setStart(const int, const int);

	void setEnd(const Point);
	void setEnd(const int, const int);

	const Point& getStart() const;
	const Point& getEnd() const;

	float gradient() const;
	float intercept() const;
	bool isParallel(const Line&) const;
	bool isPerpendicular(const Line&) const;

private:
	Point beg;
	Point end;
public:
	Point calculateMidpoint();
};