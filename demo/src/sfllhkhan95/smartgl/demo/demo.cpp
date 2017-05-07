#pragma comment(lib, "smartgl.lib")

#include "SmartGLApp.h"
#include "GL\glut.h"
#include "ui\Activity.h"
#include "ui\view\Button.h"
#include "ui\view\Animation.h"
#include "ui\view\TextView.h"

class Menu : public Activity
{
	Button buttons[5];
	Animation bookworm, background;
	TextView body, heading;

public:
	Menu()
	{
		buttons[0] = Button("=", 320, 30, 40, 40, ColorDarkSlateGrey);
		buttons[1] = Button("o", 360, 30, 40, 40, ColorDarkSlateGrey);
		buttons[2] = Button("+", 400, 30, 40, 40, ColorDarkSlateGrey);
		buttons[3] = Button("-", 440, 30, 40, 40, ColorDarkSlateGrey);
		buttons[4] = Button("x", 480, 30, 40, 40, ColorDarkSlateGrey);

		for (int i = 0; i <= 5; i++)
			background.insertFrame("res/anim/raining/frame_" + std::to_string(i) + ".png");
		background.setSpeed(0.025f);

		for (int i = 0; i <= 8; i++)
			bookworm.insertFrame("res/anim/reading/frame_" + std::to_string(i) + ".png");

		bookworm.setPosition(25, 25);
		bookworm.setSize(250, 335);
		bookworm.setSpeed(0.01f);

		body.setColor(ColorRed);
		body.setPosition(50, 500);
		body.setLineWidth(60);
		body.setFont(GLUT_BITMAP_HELVETICA_18);
		body.setText("SmartGL Graphics Library is a graphics library based on OpenGL Utility Toolkit (GLUT). It is being developed"
			" by Muhammad Saifullah Khan.\n This is a test program and shall be used to test the various features of the graphics"
			" library.");

		heading.setColor(ColorBrightGold);
		heading.setFont(GLUT_BITMAP_HELVETICA_18);
		heading.setPosition(50, 550);
		heading.setText("SmartGL Graphics Library");
	}

	void Display()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		background.Display();
		bookworm.Display();

		heading.Display();
		body.Display();
	
		for (int i = 0; i < 5; i++)
			buttons[i].Display();
	}

	void KeyboardSpecialEvents(int& key, int& x, int& y)
	{
		switch (key)
		{
		default:
			break;
		}
	}

	void MouseEvents(int& button, int& state, int& x, int& y)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (buttons[4].containsPoint(x, y))
				exit(0);

			if (buttons[0].containsPoint(x, y)){
				if (bookworm.isStopped())
				{
					background.start();
					bookworm.start();
					buttons[0].setLabel("=");
				}
				else if (bookworm.isPaused()){
					background.resume();
					bookworm.resume();
					buttons[0].setLabel("=");
				}
				else{
					background.pause();
					bookworm.pause();
					buttons[0].setLabel(">");
				}
			}

			else if (buttons[1].containsPoint(x, y)){
				bookworm.stop();
				background.stop();
				buttons[0].setLabel(">");
			}

			else if (buttons[2].containsPoint(x, y)){
				bookworm.changeSpeed(0.005f);
				background.changeSpeed(0.005f);
			}

			else if (buttons[3].containsPoint(x, y)){
				bookworm.changeSpeed(-0.005f);
				background.changeSpeed(-0.005f);
			}
		}
	}
};

int main()
{
	SmartGLApp app("SmartGL Driver Program", 800, 600);
	app.addActivity(new Menu(), "Screen_1");
	app.run();
}