#pragma once

class MouseListener
{
public:

	/*
	Virtual method, can be overriden if the sglActivity uses mouse input. Handles input from mouse clicks.
	*/
	virtual void	MouseEvents(int&, int&, int&, int&);


	/*
	Virtual method, can be overriden if the sglActivity uses mouse input. Handles events generated when mouse
	enters or exits a particular location on screen.
	*/
	virtual void	PassiveMotionEvents(int& x, int& y);


	/*
	Virtual method, can be overriden if the sglActivity uses mouse input. Handles events generated when mouse
	enters or exits a particular location on screen while clicking the mouse button.
	*/
	virtual void	ActiveMotionEvents(int&, int&);
};