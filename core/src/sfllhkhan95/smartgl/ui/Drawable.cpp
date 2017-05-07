#include "stdafx.h"
#include "Drawable.h"

#include "GL\glut.h"

Drawable::Drawable()
	: red(1.0), green(1.0), blue(1.0), alpha(1.0){}

void Drawable::setColor(const double r, const double g, const double b)
{
	red = r;
	green = g;
	blue = b;

	glColor4d(red, green, blue, alpha);
}

void Drawable::setAlpha(const double a)
{
	alpha = a;

	if (alpha < 0.0)
		alpha = 0.0;

	if (alpha > 255.0)
		alpha = 255.0;

	glColor4d(red, green, blue, alpha);
}

double Drawable::getRed()
{
	return red;
}

double Drawable::getGreen()
{
	return green;
}

double Drawable::getBlue()
{
	return blue;
}

double Drawable::getAlpha()
{
	return alpha;
}