#pragma once
#include "View.h"

class TextView : public View
{
public:
				TextView();
				TextView(char);
				TextView(const char*);
				TextView(string);
	void		Display() const;
	void		setFont(void*);
	void		setText(char);
	void		setText(string);
	void		setText(const char*);
	void		setLineWidth(int);

private:
	string		text;
	int			lineWidth;
	void*		font;
};