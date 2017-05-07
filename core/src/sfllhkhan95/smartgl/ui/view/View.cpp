#include "stdafx.h"
#include "../../globals.h"
#include "View.h"

bool View::containsPoint(const Point& _m) const
{
	return containsPoint(_m.getX(), _m.getY());
}

bool View::containsPoint(const int _mx, const int _my) const
{
	if ((_mx > getX() - getWidth() / 2 && _mx < getX() + getWidth() / 2) &&
		(SGL_GLOBAL_WINDOW->getHeight() - _my > getY() - getHeight() / 2 &&
		SGL_GLOBAL_WINDOW->getHeight() - _my < getY() + getHeight() / 2))
		return true;

	else return false;
}
