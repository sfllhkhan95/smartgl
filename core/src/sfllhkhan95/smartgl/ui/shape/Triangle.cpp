#include "stdafx.h"
#include "Line.h"
#include <iostream>
using std::cout;
#include "Triangle.h"
#include "GL\glut.h"

Triangle::Triangle()
	: A(), B(), C()
{
}

Triangle::Triangle(Point _a, Point _b, Point _c)
	: A(_a), B(_b), C(_c)
{
}

Triangle::Triangle(int _ax, int _ay, int _bx, int _by, int _cx, int _cy)
	: A(_ax, _ay), B(_bx, _by), C(_cx, _cy)
{
}

void Triangle::Display() const
{
	glBegin(GL_POLYGON);
	glVertex2i(A.getX(), A.getY());
	glVertex2i(B.getX(), B.getY());
	glVertex2i(C.getX(), C.getY());
	glEnd();
}

void Triangle::setA(const Point _a)
{
	A = _a;
}

void Triangle::setA(const int _ax, const int _ay)
{
	A = Point(_ax, _ay);
}

void Triangle::setB(const Point _b)
{
	B = _b;
}

void Triangle::setB(const int _bx, const int _by)
{
	B = Point(_bx, _by);
}

void Triangle::setC(const Point _c)
{
	C = _c;
}

void Triangle::setC(const int _cx, const int _cy)
{
	C = Point(_cx, _cy);
}

const Point& Triangle::getA() const
{
	return A;
}

const Point& Triangle::getB() const
{
	return B;
}

const Point& Triangle::getC() const
{
	return C;
}

Point Triangle::calculateMidpoint()
{
	Line AB(A, B);
	Line BC(B, C);

	Point AB_mid = AB.calculateMidpoint();
	Point BC_mid = BC.calculateMidpoint();
	
	Line L1(AB_mid, C);
	Line L2(BC_mid, A);

	// Intersection of the lines is the midpoint
	int x = (L2.intercept() - L1.intercept()) / (L1.gradient() - L2.gradient());
	int y = L1.gradient() * x + L1.intercept();

	return Point(x, y);
}