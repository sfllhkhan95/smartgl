#include "stdafx.h"
#include "Button.h"
#include "TextView.h"
#include "../shape/Rectangle.h"

vector<Button*> Button::buttons;

Button::Button(string str) : Button(str, 0, 0, 0, 0) 
{
}

Button::Button(string str, int x, int y, double wd, double ht, double r, double g, double b) : label(str), image(NULL)
{
	this->setPosition(x, y);
	this->setSize(wd, ht);
	this->setColor(r, g, b);

	buttons.push_back(this);
}

Button::Button(ImageView* _image, int x, int y, double wd, double ht, double r, double g, double b)
	: Button("", x, y, wd, ht, r, g, b)
{
	this->setImage(_image);
}

void Button::setLabel(const string& _l)
{
	label = _l;
}

const string& Button::getLabel() const
{
	return label;
}

void Button::removeLabel()
{
	label = "";
}

bool Button::hasLabel() const
{
	return label == "" ? false : true;
}

void Button::setImage(ImageView *_image)
{
	if (image != NULL)
		delete image;

	image = _image;
	image->setPosition(getX(), getY());
	image->setSize(getWidth(), getHeight());
}

const ImageView& Button::getImage() const
{
	return *image;
}

void Button::removeImage()
{
	image = NULL;
}

bool Button::hasImage() const
{
	return image == NULL ? false : true;
}

void Button::Display() const
{
	int x = this->getX();
	int y = this->getY();
	int w = this->getWidth();
	int h = this->getHeight();

	// IMAGE
	if (image)
	{
		image->setAlpha(255.f * alpha);
		image->Display();
	}
	else
	{
		// SHADOW
		Rectangle shadow(x + 2, y - 2, w, h);
		shadow.setColor(ColorBlack);
		shadow.setAlpha(0.5);
		shadow.Display();

		//BUTTON
		Rectangle button(x, y, w, h);
		button.setColor(red, green, blue);
		button.setAlpha(alpha / 2);
		button.Display();
		
		// LABEL
		TextView text(label);
		text.setColor(ColorWhite);
		text.setPosition(x - label.size() * 4.2, y - 8);
		text.Display();
	}
}