#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "../Transformable.h"
#include "../Drawable.h"
#include "../shape/Point.h"
#include "GL\glut.h"

#include <string>
using std::string;

class View : public Transformable, public Drawable
{
public:
	bool	containsPoint(const Point&) const;
	bool	containsPoint(const int, const int) const;
};

#endif