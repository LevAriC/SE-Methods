#pragma once
#include "Control.h"
#include "Border.h"

class TextBox : public Control
{
	string text;
	bool isFocused;
	int width;
	int height;
	int cursor;

public:
	TextBox(Border*, short, short, int, int);
	bool canGetFocus();
	void onFocus(bool);
	void draw(Graphics&, int, int, size_t);
	void keyDown(int, char, Graphics&);
	void mousePressed(int, int, bool);
	int getWidth();
};