#include "stdafx.h"
#include "../AppWindow.h"
#include "../ui/ActivityManager.h"
#include "GL\glut.h"

AppWindow* SGL_GLOBAL_WINDOW;

void Display()
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->Display();

	glutSwapBuffers();
}

void ReshapeGL(int w, int h)
{
	// Clear previous frame
	glClear(GL_COLOR_BUFFER_BIT);

	// Set up new viewport
	int x = w - SGL_GLOBAL_WINDOW->getWidth() / SGL_GLOBAL_WINDOW->getHeight() * h;
	glViewport(x / 2, 0, SGL_GLOBAL_WINDOW->getWidth() / SGL_GLOBAL_WINDOW->getHeight() * h, h);

	// Resize canvas
	glMatrixMode(GL_PROJECTION);				// Switch to projection mode
	glLoadIdentity();							// Reset matrix
	glOrtho(0.0, SGL_GLOBAL_WINDOW->getWidth(),
		0.0, SGL_GLOBAL_WINDOW->getHeight(),
		-1.0, 1.0);							// Reset (0,0) to the bottom-left of screen
}

void KeyboardEvents(unsigned char key, int x, int y)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->KeyboardEvents(key, x, y);

	glutPostRedisplay();
}

void KeyboardUpEvents(unsigned char key, int x, int y)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->KeyboardUpEvents(key, x, y);

	glutPostRedisplay();
}

void KeyboardSpecialEvents(int key, int x, int y)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->KeyboardSpecialEvents(key, x, y);

	glutPostRedisplay();
}

void KeyboardSpecialUpEvents(int key, int x, int y)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->KeyboardSpecialUpEvents(key, x, y);

	glutPostRedisplay();
}

void MouseEvents(int button, int state, int x, int y)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->MouseEvents(button, state, x, y);

	glutPostRedisplay();
}

void PassiveMotionEvents(int x, int y)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->PassiveMotionEvents(x, y);

	glutPostRedisplay();
}

void ActiveMotionEvents(int x, int y)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->ActiveMotionEvents(x, y);

	glutPostRedisplay();
}

void TimerGL(int t)
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
	{
		glutTimerFunc(33, TimerGL, t);
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->TimerGL(t);
	}

	glutPostRedisplay();
}

void IdleGL()
{
	if (SGL_GLOBAL_WINDOW->getManager().getCurrentActivity())
		SGL_GLOBAL_WINDOW->getManager().getCurrentActivity()->IdleGL();

	glutPostRedisplay();
}