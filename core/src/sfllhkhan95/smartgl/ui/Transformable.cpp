#include "stdafx.h"
#include "../globals.h"
#include "Transformable.h"

#include <cmath>
#include <iostream>

using namespace std;

Transformable::Transformable()
	: width(800.0), height(600.0), xPosition(0.0), yPosition(0.0)
{
	if (SGL_GLOBAL_WINDOW){
		width = SGL_GLOBAL_WINDOW->getWidth();
		height = SGL_GLOBAL_WINDOW->getHeight();
	}

}


void Transformable::setSize(const double& wd, const double& ht)
{
	width = wd;
	height = ht;
}


void Transformable::setPosition(const double& x, const double& y)
{
	xPosition = x;
	yPosition = y;
}


void Transformable::setRelativePosition(const Transformable& GameObject, const double& x, const double& y)
{
	xPosition = GameObject.getX() + x;
	yPosition = GameObject.getY() + y;
}


Transformable& Transformable::get() { return *this; }


const double& Transformable::getX() const{ return xPosition; }


const double& Transformable::getY() const{ return yPosition; }


const double& Transformable::getWidth() const{ return width; }


const double& Transformable::getHeight() const{ return height; }


const double Transformable::getRelativeX(const Transformable& GameObject) const{ return xPosition - GameObject.getX(); }


const double Transformable::getRelativeY(const Transformable& GameObject) const{ return yPosition - GameObject.getY(); }


const double Transformable::getDistance(const Transformable& GameObject, const char& axis)
{
	// Calculate midpoint of calling object
	auto thisX = getX() + getWidth() / 2;
	auto thisY = getY() + getHeight() / 2;

	// Calculate midpoint of passed object
	auto passX = GameObject.getX() + GameObject.getWidth() / 2;
	auto passY = GameObject.getY() + GameObject.getHeight() / 2;

	if (axis == ' ')
		return sqrt(pow((getX() - GameObject.getX()), 2) + pow((getY() - GameObject.getY()), 2));

	else if (axis == 'x' || axis == 'X')
		return abs(getX() - GameObject.getX());

	else if (axis == 'y' || axis == 'Y')
		return abs(getY() - GameObject.getY());

	else throw std::invalid_argument("Transformable::getDistance(GameObject, axis) - Invalid axis given, can be 'x' or 'y' only.");
}


void Transformable::translate(const char& axis, const double& deltaPos)
{
	if (axis == 'X' || axis == 'x')
		xPosition += deltaPos;

	else if (axis == 'Y' || axis == 'y')
		yPosition += deltaPos;

	else throw std::invalid_argument("Transformable::translate(axis, deltaPos) - Invalid axis given, can be 'x' or 'y' only.");
}