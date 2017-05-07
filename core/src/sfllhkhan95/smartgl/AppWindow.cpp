#include "stdafx.h"
#include "AppWindow.h"
#include "io/Callbacks.h"
#include "GL\glut.h"

bool AppWindow::created = false;
AppWindow* AppWindow::ourInstance;


AppWindow* AppWindow::getInstance(){
	if (!created){
		created = true;
		ourInstance = new AppWindow();
	}
	
	return ourInstance;
}

AppWindow::AppWindow()
	: sglWindowTitle("SmartGL Window")	// Default title
	, sglWindowWidth(800.0)				// Default width
	, sglWindowHeight(600.0)			// Default height
	, sglWindowXPos(-1)					// If the user does not change this value, window will be centered on screen
	, sglWindowYPos(-1)					// If the user does not change this value, window will be centered on screen
	, sglWindowFullScreen(false)		// Window is not in full screen mode by default
	, sglWindowContentFit(FIT)			// Default resize behavior is FIT
	, sglWindowId(-1)					// Window has not id because it has not been created yet
{ }

AppWindow::~AppWindow()
{
	if (sglWindowId != -1) {
		glutDestroyWindow(sglWindowId);
		sglWindowId = -1;
	}
}

void AppWindow::setTitle(char* title)
{
	sglWindowTitle = title;
}

char* AppWindow::getTitle() const
{
	return sglWindowTitle;

}

void AppWindow::setResolution(const double w, const double h)
{
	sglWindowWidth = w;
	sglWindowHeight = h;
}

void AppWindow::setPosition(const int x, const int y)
{
	sglWindowXPos = x;
	sglWindowYPos = y;
}

double AppWindow::getWidth() const
{
	return sglWindowWidth;
}

double AppWindow::getHeight() const
{
	return sglWindowHeight;
}

int AppWindow::getPosX() const
{
	return sglWindowXPos;
}

int AppWindow::getPosY() const
{
	return sglWindowYPos;
}

int AppWindow::getId() const
{
	return sglWindowId;
}

void AppWindow::enterFullScreenMode()
{
	sglWindowFullScreen = true;
	glutFullScreen();
}

void AppWindow::enterWindowedMode()
{
	glutPositionWindow(sglWindowXPos, sglWindowYPos);
	glutReshapeWindow(sglWindowWidth, sglWindowHeight);
	sglWindowFullScreen = false;
}

bool AppWindow::isFullScreen() const
{
	return sglWindowFullScreen;
}

void AppWindow::onResize(const ContentFit contentFit)
{
	sglWindowContentFit = contentFit;
}

int AppWindow::create()
{
	// Set GLUT window mode
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);

	// Set GLUT window Size
	glutInitWindowSize(sglWindowWidth, sglWindowHeight);

	// Position GLUT window in middle of the screen
	int iScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
	int iScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);
	sglWindowXPos = (iScreenWidth - sglWindowWidth) / 2;
	sglWindowYPos = (iScreenHeight - sglWindowHeight) / 2;
	glutInitWindowPosition(sglWindowXPos, sglWindowYPos);

	// Create the GLUT window
	sglWindowId = glutCreateWindow(sglWindowTitle);

	registerCallbacks();

	// Setup initial GL State
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClearDepth(1.0f);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, sglWindowWidth, 0.0, sglWindowHeight, -1.0, 1.0);
	glViewport(0, 0, sglWindowWidth, sglWindowHeight);

	return sglWindowId;
}

void AppWindow::registerCallbacks()
{
	glutDisplayFunc(Display);
	glutReshapeFunc(ReshapeGL);

	glutKeyboardFunc(KeyboardEvents);
	glutKeyboardUpFunc(KeyboardUpEvents);
	glutSpecialFunc(KeyboardSpecialEvents);
	glutSpecialUpFunc(KeyboardSpecialUpEvents);

	glutMouseFunc(MouseEvents);
	glutPassiveMotionFunc(PassiveMotionEvents);
	glutMotionFunc(ActiveMotionEvents);

	glutIdleFunc(IdleGL);
	glutTimerFunc(30, TimerGL, 0);
}

ActivityManager& AppWindow::getManager()
{
	return mActivityManager;
}