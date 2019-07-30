#pragma once
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class MsgBox : public Control
{
	Panel panel;
	Label label;
	bool isVisible;

public:
	MsgBox(short, short, string);
	MsgBox(short, short, string, Color, Color);
	void draw(Graphics&, int, int, size_t);
	bool canGetFocus();
	void buttonEvent();
};
