#pragma once

/*
ContentFit tells how the content of the sglWindow will be resized when the window's size is
changed by the user. It can have three possible values; FIT, FILL and STRETCH.
*/
enum ContentFit
{
	/*
	The content will be resized such that it takes up maximum space within the window while not
	distorting its original aspect ratio. The content will be centered inside the window and any
	surrounding blank area will have black color. The content will always fill the window on at
	least one of the two axes x and y.
	*/
	FIT,

	/*
	The content will be resized such that it fills up the entire window. Any overflowing content
	will be cropped. The content will be centered and the original aspect ration will not be
	distorted.
	*/
	FILL,

	/*
	The content will be resized to fit the exact size of the window regardless of the original
	aspect ratio of the content.
	*/
	STRETCH
};