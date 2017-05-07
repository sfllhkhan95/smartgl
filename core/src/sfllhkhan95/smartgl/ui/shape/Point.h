#pragma once

class Point
{
public:
	Point(int = 0, int = 0);

	void setX(const int);
	void setY(const int);
	void set(const int, const int);

	int getX() const;
	int getY() const;

	double distance(const Point&) const;

	void Display() const{};

	Point operator - (const Point&) const;
	Point operator + (const Point&) const;
	Point operator * (const Point&) const;
	Point operator / (const Point&) const;
	Point operator % (const Point&) const;
	Point& operator+=(const Point&);							// Assignment addition
	Point& operator-=(const Point&);							// Assignment subtraction
	Point& operator*=(const Point&);							// Assignment multiplication
	Point& operator/=(const Point&);							// Assignment division
	Point& operator%=(const Point&);							// Assignment modulo
	bool operator==(const Point&) const;						// Equality
	bool operator <(const Point&) const;						// Less than
	bool operator<=(const Point&) const;						// Less than or equal to
	bool operator >(const Point&) const;						// Greater than
	bool operator>=(const Point&) const;						// Greater than or equal to
private:
	int x;
	int y;
};

