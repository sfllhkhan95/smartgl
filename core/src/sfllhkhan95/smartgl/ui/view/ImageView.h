#ifndef TEXTURE_H
#define TEXTURE_H

#include "View.h"


class ImageView : public View
{
public:
					~ImageView();

	virtual void	Display() const;
	ImageView&		loadFromFile(const string&);

private:
	int				loadPNG(const string&, unsigned int&);
	int				loadTGA(const string&, unsigned int&);
	bool			checkSize(int&);

	char*			GetData(FILE&, int&, int&);
	unsigned char*	GetRGBA(FILE&, int&);
	unsigned char*	GetRGB(FILE&, int&);
	unsigned char*	GetGray(FILE&, int&);

	GLuint			TexID = 0;
	GLenum			texFormat;
};

#endif