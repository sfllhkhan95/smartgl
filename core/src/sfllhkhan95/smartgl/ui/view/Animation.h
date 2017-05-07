#pragma once
#include <vector>
using std::vector;

#include "ImageView.h"

class Animation : public View
{
public:
					Animation();
					~Animation();
	void			insertFrame(const string&);
	void			setSpeed(const float);
	void			changeSpeed(const float);
	void			Display() const;

	bool			isRunning() const;
	bool			isPaused() const;
	bool			isStopped() const;

	void			start();
	void			stop();
	void			pause();
	void			resume();
	void			repeat(bool);

private:
	bool			running;
	bool			paused;
	bool			loop;

	float			animationRate;
	mutable float	activeFrame;
	int				noOfFrames;

	vector<ImageView*> animationFrames;
};

