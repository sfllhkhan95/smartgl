#pragma once
#include <vector>
using std::vector;

#include "ImageView.h"

class Button : public View
{
public:
	static vector<Button*> buttons;

					Button(string = "");

					Button(string label, int x, int y, double width, double height,
							double r = 1.0, double g = 1.0, double b = 1.0);

					Button(ImageView *img, int x, int y, double width, double height,
							double r = 1.0, double g = 1.0, double b = 1.0);

	void			setLabel(const string& label);
	void			removeLabel();

	const string&	getLabel() const;
	bool			hasLabel() const;

	void			setImage(ImageView* image);
	void			removeImage();

	const ImageView& getImage() const;
	bool			hasImage() const;

	void			Display() const;

private:
	mutable string	label;
	ImageView*		image;
};