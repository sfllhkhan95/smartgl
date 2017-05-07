#include "stdafx.h"
#include "SmartGLApp.h"
#include "globals.h"
#include "GL\glut.h"

SmartGLApp::SmartGLApp(char* title, double width, double height)
{
	SGL_GLOBAL_WINDOW = AppWindow::getInstance();
	SGL_GLOBAL_WINDOW->setTitle(title);
	SGL_GLOBAL_WINDOW->setResolution(width, height);
	SGL_GLOBAL_WINDOW->create();
}

void SmartGLApp::addActivity(Activity* activity, const char* id){
	SGL_GLOBAL_WINDOW->getManager().addActivity(activity, id);
}

void SmartGLApp::run(){
	glutMainLoop();
}