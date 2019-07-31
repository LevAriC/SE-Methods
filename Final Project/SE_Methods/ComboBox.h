#pragma once
#include "Control.h"

class ComboBox :public Control
{
	int width;
	int currentIndex;
	int selectedIndex;
	bool isOpen;
	string textBox;
	vector<string> values;

public:
	ComboBox(Border*, short, short, vector<string>);
	ComboBox(Border*, short, short, vector<string>, Color, Color);
	void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
	void keyDown(int, char, Graphics&);
	bool canGetFocus();
	bool isControlsList();
	bool isLastIndex();
	int getWidth();
};