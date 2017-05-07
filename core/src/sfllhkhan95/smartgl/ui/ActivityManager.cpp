#include "stdafx.h"
#include "ActivityManager.h"
#include <cassert>
using std::logic_error;

ActivityManager::ActivityManager()
	: activeScene(NULL)
{

}

void ActivityManager::addActivity(Activity* activity, std::string id)
{
	// Insert and check success
	auto inserted = allScenes.insert(std::make_pair(id, std::move(activity)));
	assert(inserted.second);

	setActive(id);
}

void ActivityManager::removeActivity(std::string id)
{
	delete activeScene;
	activeScene = NULL;
	allScenes.erase(id);
}

void ActivityManager::setActive(std::string id)
{
	// Find the required scene and set it as active scene
	auto found = allScenes.find(id);
	if (found == allScenes.end())
		throw logic_error("sglActivity '" + id + "' not created yet\n");

	if (activeScene)
		activeScene->onStop();

	activeScene = found->second;
	activeScene->onStart();
}

Activity* ActivityManager::getCurrentActivity() const
{
	return activeScene;
}