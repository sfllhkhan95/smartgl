#pragma once
#include "Activity.h"
#include <string>
#include <map>

using std::string;
using std::map;

class ActivityManager
{
public:
	ActivityManager();
	void addActivity(Activity*, string);
	void removeActivity(string);
	void setActive(string);
	Activity* getCurrentActivity() const;

private:
	Activity* activeScene;
	map<string, Activity*> allScenes;
};