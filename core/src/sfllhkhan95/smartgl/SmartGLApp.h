#pragma once
#include "AppWindow.h"
#include "ui/ActivityManager.h"

class SmartGLApp
{
public:
	SmartGLApp(char* title, double width, double height);
	void addActivity(Activity* activity, const char* id);
	void run();
};
