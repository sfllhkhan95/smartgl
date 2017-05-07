#include "stdafx.h"

#pragma comment (lib, "soil.lib")

#include "SOIL/SOIL.h"
#include "GL/glut.h"
#include "GL/GL.H"
#include "ImageView.h"
#include <cmath>

//-------------------------------------------------------------------------------------------//
//                                                                                           //
//                                                                                           //
//       PUBLIC INTERFACE:                                                                   //
//                                                                                           //
//       1) ~ImageView()									- Default Destructor             //
//       2) loadFromFile(string)							- Loads texture from image file  //
//       3) Display()										- Renders texture on to screen   //
//                                                                                           //
//                                                                                           //
//-------------------------------------------------------------------------------------------//


/*
ImageView::~ImageView() is the default destructor of ImageView class and takes care of
reclaiming any used memory by deleting the OpenGL textures if they exist
*/
ImageView::~ImageView()
{
	if (TexID != 0) glDeleteTextures(1, &TexID);
}


/*
ImageView::loadFromFile(FILEPATH) reads a TGA file into memory from FILEPATH. The TGA file
must have dimensions as power of 2 and less than 1024 to be loaded successfully.
*/
ImageView& ImageView::loadFromFile(const string& path)
{
	glGenTextures(1, &TexID);

	if (path.find(".tga") != string::npos ||
		path.find(".TGA") != string::npos)
	{
		loadTGA(path, TexID);
	}
	else
	{
		loadPNG(path, TexID);
	}
	return *this;
}

/*
ImageView::Display() tries to Display() the loaded texture in GLUT window. loadFromFile() method
must be implicitly called before calling the Display() method. If not, an exception is raised
and rendering ImageView on to GLUT window fails.
*/
void ImageView::Display() const
{
	// Throw exception if no texture has been loaded
	if (TexID == 0)
		throw std::logic_error("ImageView::Display() - Load file before drawing");

	// Enable texture mapping
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, TexID);

	// Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// Draw the canvas
	glColor4d(red, green, blue, alpha);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0.0, 0.0);	glVertex2d(getX(), getY());
		glTexCoord2f(1.0, 0.0);	glVertex2d(getX() + getWidth(), getY());
		glTexCoord2f(1.0, 1.0);	glVertex2d(getX() + getWidth(), getY() + getHeight());
		glTexCoord2f(0.0, 1.0);	glVertex2d(getX(), getY() + getHeight());
	}
	glEnd();

	// Disable texture mapping
	glDisable(GL_TEXTURE_2D);
}


//-------------------------------------------------------------------------------------------//
//                                                                                           //
//                                                                                           //
//       IMPLEMENTATION (PRIVATE);                                                           //
//                                                                                           //
//       1) loadTGA(PATH, ID)	- Load up a targa file. Supported types are 8, 24 and 32     //
//								  uncompressed images.                                       //
//       2) checkSize(SIZE)		- Make sure its a power of 2.                                //
//       3) GetRGBA(FILE, SIZE) - Reads in RGBA data for a 32bit image.                      //
//       4) GetRGB(FILE, SIZE)	- Reads in RGB data for a 24bit image.                       //
//       5) GetGray(FILE, SIZE) - Read the grayscale image data. Used as an alpha channel.   //
//       6) GetData(FILE, BITS)	- Reads the image data for the specified bit depth.          //
//                                                                                           //
//                                                                                           //
//-------------------------------------------------------------------------------------------//

int ImageView::loadPNG(const string &path, GLuint &id)
{
	id = SOIL_load_OGL_texture
		(
		path.c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	return 1;
}

int ImageView::loadTGA(const string &path, GLuint &id)
{
	unsigned char type[4];
	unsigned char info[7];
	unsigned char *imageData(nullptr);
	int imageWidth, imageHeight;
	int imageBits, Size;
	FILE *s(nullptr);

//	fopen_s(&s, path.c_str(), "r+bt");
//	if (s == nullptr || s == NULL)
	if (!(s = fopen(path.c_str(), "r+bt")))
		throw std::runtime_error(string("ImageView::loadFromFile(") + path + string(") - File not found"));

	fread(&type, sizeof(char), 3, s);		// read in colormap info and image type, byte 0 ignored
	fseek(s, 12, SEEK_SET);					// seek past the header and useless info
	fread(&info, sizeof(char), 6, s);

	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
		throw std::runtime_error("ImageView::loadFromFile(" + path + ") - Bad image (color mapped or compressed)");

	imageWidth = info[0] + info[1] * 256;
	imageHeight = info[2] + info[3] * 256;
	imageBits = info[4];

	Size = imageWidth * imageHeight;

	/* make sure dimension is a power of 2 */
	if (!checkSize(imageWidth) || !checkSize(imageHeight))
		throw std::runtime_error("ImageView::loadFromFile(" + path + ") - Dimensions not power of 2");

	/* make sure we are loading a supported type */
	if (imageBits != 32 && imageBits != 24 && imageBits != 8)
		throw std::runtime_error("ImageView::loadFromFile(" + path + ") - 8, 24 and 32 bit supported only");

	imageData = (unsigned char*)GetData(*s, Size, imageBits);

	/* no image data */
	if (imageData == nullptr)
		throw std::runtime_error("ImageView::loadFromFile(" + path + ") - No data found in image file");

	fclose(s);

	glBindTexture(GL_TEXTURE_2D, id);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, texFormat, imageWidth, imageHeight, 0, texFormat, GL_UNSIGNED_BYTE, imageData);

	/* release data, its been uploaded */
	free(imageData);

	return 1;
}

bool ImageView::checkSize(int& x)
{
	if (x == 2 ||
		x == 4 ||
		x == 8 ||
		x == 16 ||
		x == 32 ||
		x == 64 ||
		x == 128 ||
		x == 256 ||
		x == 512 ||
		x == 1024) return true;
	
	else return false;
}

unsigned char* ImageView::GetRGBA(FILE &s, int &Size)
{
	unsigned char *rgba(nullptr);
	unsigned char temp;
	int bread;
	int i;

	rgba = (unsigned char*)malloc(Size * 4);

	if (rgba == nullptr)
		return 0;

	bread = fread(rgba, sizeof(unsigned char), Size * 4, &s);

	/* TGA is stored in BGRA, make it RGBA */
	if (bread != Size * 4)
	{
		free(rgba);
		return 0;
	}

	for (i = 0; i < Size * 4; i += 4)
	{
		temp = rgba[i];
		rgba[i] = rgba[i + 2];
		rgba[i + 2] = temp;
	}

	texFormat = GL_RGBA;

	return rgba;
}

unsigned char *ImageView::GetRGB(FILE &s, int &Size)
{
	unsigned char *rgb(nullptr);
	unsigned char temp;
	int bread;
	int i;

	rgb = (unsigned char *)malloc(Size * 3);

	if (rgb == nullptr)
		return 0;

	bread = fread(rgb, sizeof(unsigned char), Size * 3, &s);

	if (bread != Size * 3)
	{
		free(rgb);
		return 0;
	}

	/* TGA is stored in BGR, make it RGB */
	for (i = 0; i < Size * 3; i += 3)
	{
		temp = rgb[i];
		rgb[i] = rgb[i + 2];
		rgb[i + 2] = temp;
	}

	texFormat = GL_RGB;

	return rgb;
}

unsigned char *ImageView::GetGray(FILE &s, int &Size)
{
	unsigned char *grayData(nullptr);
	int bread;

	grayData = (unsigned char *)malloc(Size);

	if (grayData == nullptr)
		return 0;

	bread = fread(grayData, sizeof(unsigned char), Size, &s);

	if (bread != Size)
	{
		free(grayData);
		return 0;
	}

	texFormat = GL_ALPHA;

	return grayData;
}

char* ImageView::GetData(FILE &s, int &sz, int &iBits)
{
	if (iBits == 32)
		return (char*)GetRGBA(s, sz);
	else if (iBits == 24)
		return (char*)GetRGB(s, sz);
	else if (iBits == 8)
		return (char*)GetGray(s, sz);
	else
		return 0;
}