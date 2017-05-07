#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "Colors.h"

class Drawable
{
public:
					Drawable();

	void			setColor(const double, const double, const double);
	void			setAlpha(const double);

	double			getRed();
	double			getGreen();
	double			getBlue();
	double			getAlpha();

	virtual void	Display() const = 0;

protected:
	double			red;
	double			green;
	double			blue;
	double			alpha;
};

#endif