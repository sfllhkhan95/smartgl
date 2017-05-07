#pragma once
#include "View.h"

class EditText : public View
{
	string text = "";
public:
	void getInput(char key)
	{
	//	if (isActive())
		{
			// If backspace is pressed while text field has some text, remove last letter
			if (key == 8 && !text.empty())
				text.pop_back();

			// Else add the character key pressed into the text
			else text.push_back(key);
		}
	}
};