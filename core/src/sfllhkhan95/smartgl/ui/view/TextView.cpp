#include "stdafx.h"

#include "TextView.h"
#include "GL\GLUT.H"


TextView::TextView()
	: lineWidth(50), font(GLUT_BITMAP_HELVETICA_18)
{
	setText("");
}


TextView::TextView(char c)
	: TextView()
{
	setText(c);
}


TextView::TextView(const char* txt)
	: TextView()
{
	setText(txt);
}


TextView::TextView(string txt)
	: TextView()
{
	setText(txt);
}


void TextView::Display() const
{
	glColor4d(red, green, blue, alpha);
	glRasterPos2d(getX(), getY());

	int count = 1;
	for (int i = 0; i < text.length(); i++)
	{
		if (count == 1 && text[i] == ' ')
			continue;

		if (text[i] == '\n')
		{
			if (text[i + 1] >= '0' && text[i + 1] <= '9')
			{
				GLdouble position[4] = { 0.0 };
				glGetDoublev(GL_CURRENT_RASTER_POSITION, position);
				glRasterPos2d(getX(), position[1] - 20);
				count = 1;
			}
			else
			{
				glutBitmapCharacter(font, ' ');
			}
			continue;
		}

		if (count % lineWidth == 0)
		{
			if (text[i + 1] >= 'a' && text[i + 1] <= 'z')
				glutBitmapCharacter(font, '-');

			GLdouble position[4] = { 0.0 };
			glGetDoublev(GL_CURRENT_RASTER_POSITION, position);
			glRasterPos2d(getX(), position[1] - 20);
		}

		glutBitmapCharacter(font, text[i]);
		count++;
	}

	return;
}


void TextView::setLineWidth(int noOfCharacters)
{
	lineWidth = noOfCharacters;
}


void TextView::setFont(void* name)
{
	font = name;
}


void TextView::setText(char c)
{
	text = c;
}


void TextView::setText(const char* txt)
{
	text = txt;
}


void TextView::setText(string txt)
{
	text = txt;
}