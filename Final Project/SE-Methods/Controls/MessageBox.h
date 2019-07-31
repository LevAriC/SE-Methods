#pragma once
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class MsgBox : public Control
{
	Label label;
	Button okButton, cancelButton;
	string text;
	bool isVisible;

public:
	MsgBox(Border* border, short, short, string);
	MsgBox(Border* border, short, short, string, Color, Color);
	void draw(Graphics&, int, int, size_t);
	bool canGetFocus();
	void buttonEvent();
};
