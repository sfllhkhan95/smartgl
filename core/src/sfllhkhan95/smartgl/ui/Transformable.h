#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H


class Transformable
{
public:
	explicit		Transformable();

	void			setSize(const double&, const double&);
	void			setPosition(const double&, const double&);
	void			setRelativePosition(const Transformable&, const double&, const double&);

	Transformable&	get();
	const double&	getX() const;
	const double&	getY() const;
	const double&	getWidth() const;
	const double&	getHeight() const;
	const double	getRelativeX(const Transformable&) const;
	const double	getRelativeY(const Transformable&) const;
	const double	getDistance(const Transformable&, const char& = ' ');

	void			translate(const char&, const double&);

protected:
	double			xPosition, yPosition;
	double			width, height;
};


#endif