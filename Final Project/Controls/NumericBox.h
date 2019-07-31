#pragma once
#include "Control.h"
#include "Button.h"

class NumericBox : public Control {
	int minNum;
	int maxNum;
	int value;
	int width;

public:
	NumericBox(Border*, short, short, int, int);
	NumericBox(Border*, short, short, int, int, Color, Color);
	int getWidth();
	void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
};