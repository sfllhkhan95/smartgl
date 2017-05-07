#pragma once
class KeyboardListener
{
public:
	/*
	Virtual method, can be overriden if the sglActivity uses keyboard input. Handles input from character keys
	of the keyboard. Events generated on key press are handled here.
	*/
	virtual void	KeyboardEvents(unsigned char&, int&, int&);


	/*
	Virtual method, can be overriden if the sglActivity uses keyboard input. Handles input from character keys
	of the keyboard. Events generated on key release are handled here.
	*/
	virtual void	KeyboardUpEvents(unsigned char&, int&, int&);


	/*
	Virtual method, can be overriden if the sglActivity uses keyboard input. Handles input from special keys of
	the keyboard (i.e. the arrow keys, Home, Tab, Shift, Ctrl, Delete, etc). Events generated on key press
	are handled here.
	*/
	virtual void	KeyboardSpecialEvents(int&, int&, int&);


	/*
	Virtual method, can be overriden if the sglActivity uses keyboard input. Handles input from special keys of
	the keyboard (i.e. the arrow keys, Home, Tab, Shift, Ctrl, Delete, etc). Events generated on key release
	are handled here.
	*/
	virtual void	KeyboardSpecialUpEvents(int&, int&, int&);
};