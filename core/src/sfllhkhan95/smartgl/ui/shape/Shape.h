#pragma once
#include <iostream>
#include "../Drawable.h"
#include "../Transformable.h"
#include "Point.h"

class Shape : public Drawable, public Transformable
{
public:
	Shape()
	{
	}

	Shape(const Point _m)
		: midpoint(_m)
	{
	}

	Shape(const int _mx, const int _my)
		: midpoint(_mx, _my)
	{
	}

	virtual ~Shape()
	{
	}

	const Point& getMidpoint() const
	{
		return midpoint;
	}

	void setMidpoint(const Point _m)
	{
		midpoint = _m;
	}

	void setMidpoint(const int _mx, const int _my)
	{
		midpoint.set(_mx, _my);
	}

private:
	Point midpoint;
};