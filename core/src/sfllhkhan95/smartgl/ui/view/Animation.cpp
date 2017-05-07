#include "stdafx.h"
#include "Animation.h"


Animation::Animation()
	: noOfFrames(0), activeFrame(0), animationRate(0)
{
}

Animation::~Animation()
{
	for (auto frame : animationFrames)
		delete frame;
}

void Animation::setSpeed(const float _r)
{
	animationRate = _r;

	if (animationRate > 1.f)
		animationRate = 1.f;

	else if (animationRate < 0.f)
		animationRate = 0.f;
}

void Animation::changeSpeed(const float _r)
{
	setSpeed(animationRate + _r);
}

void Animation::insertFrame(const string& filename)
{
	auto frame = new ImageView();
	frame->loadFromFile(filename);

	animationFrames.push_back(frame);
	noOfFrames++;
}

void Animation::Display() const
{
	animationFrames[activeFrame]->setSize(width, height);
	animationFrames[activeFrame]->setPosition(xPosition, yPosition);
	animationFrames[activeFrame]->Display();

	if (running)
		activeFrame += 1 * animationRate;

	if (loop && activeFrame >= noOfFrames)
			activeFrame = 0;
}

bool Animation::isRunning() const
{
	return running;
}

bool Animation::isPaused() const
{
	return paused;
}

bool Animation::isStopped() const
{
	return (!running && !paused);
}

void Animation::start()
{
	running = true;
	paused = false;
	activeFrame = 0;
}

void Animation::stop()
{
	running = false;
	paused = false;
	activeFrame = 0;
}

void Animation::pause()
{
	running = false;
	paused = true;
}

void Animation::resume()
{
	running = true;
	paused = false;
}

void Animation::repeat(bool _repeat)
{
	loop = _repeat;
}