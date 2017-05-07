#pragma once
#include "ContentFit.h"
#include "ui/ActivityManager.h"

/*
	Allows creation of a SGL Window. Only one instance of this class may be created.
*/
class AppWindow
{
public:
	static bool created;
	static AppWindow* getInstance();
	
	// Default destructor
	~AppWindow();                               

	// Sets the title of the window
	void setTitle(char*);

	// Tells the title of the window
	char* getTitle() const;

	// Sets the width and height (in pixels) of the window. This method can only be used before calling the create() method
	void setResolution(const double, const double);

	// Positions window on the device screen. Top-left corner has coordinates (0, 0). This method can only be used before calling the create() method
	void setPosition(const int, const int);

	// Tells the width of the window. A sglWindow has a default width of 800px.
	double getWidth() const;

	// Tells the height of the window. A sglWindow has a default height of 600px
	double getHeight() const;

	// Tells the position of window on x-axis relative to device screen
	int getPosX() const;

	// Tells the position of window on y-axis relative to device screen
	int getPosY() const;

	// Tells the id of the window
	int getId() const;

	// Makes the content appear full-screened without an enclosing window
	void enterFullScreenMode();

	// Makes the content appear in a window
	void enterWindowedMode();

	// Returns true if the window is in full screen mode
	bool isFullScreen() const;

	// Specifies how the content should be resized when window is rezied. Default behavior is FIT
	void onResize(const ContentFit);

	// Creates and displays the window, and returns the id of the window
	int create();

	// Returns reference to the ActivityManager associated with this window
	ActivityManager& getManager();

private:
	static AppWindow* ourInstance;

	int        sglWindowId;              // Unique numeric identifier assigned to the window
	double     sglWindowWidth;           // Width of the window in pixels
	double     sglWindowHeight;          // Height of the window in pixels
	int        sglWindowXPos;            // Position of the window on x-axis relative to device screen
	int        sglWindowYPos;            // Position of the window on y-axis relative to device screen
	bool       sglWindowFullScreen;      // Flag to indicate if the window is in full screen mode or not
	ContentFit sglWindowContentFit;      // Specifies the behavior of window content when window is resized
	char*      sglWindowTitle;           // Title of the window which appears in Title Bar

	ActivityManager mActivityManager; // sglActivity manager associated with this window
	void registerCallbacks();

	// Default constructor
	AppWindow();
};