#pragma once

#include "Graphics.h"
#include "Border.h"
#include <vector>

using namespace std;

class Control
{
private:
	static Control* focusedControl;

protected:
	short left;
	short top;
	short width;
	Color backgroundColor;
	Color foregroundColor;
	Border* border;

public:
	Control() {};
	Control(short, short);
	Control(short, short, Border*);

	static Control* getFocus();
	static bool setFocus(Control&);
	virtual void draw(Graphics&, int, int, size_t) = 0;
	virtual void mousePressed(int, int, bool) {};
	virtual void keyDown(int, char, Graphics&) {};
	virtual short getLeft();
	virtual short getTop();
	virtual void getAllControls(vector<Control*>*) {};
	virtual bool canGetFocus();
	
	virtual void setBackgroundColor(Color);
	virtual void setForegroundColor(Color);
	virtual Color getBackgroundColor();
	virtual Color getForegroundColor();
	virtual void setBorder(Border*);
	virtual void onFocus(bool) {};
	virtual void setWidth(int);
	virtual int getWidth();
	virtual bool isControlsList();
	virtual bool isLastIndex();
	virtual void changeFocusedColor();
	virtual void buttonEvent() {};

	~Control() {};
};

