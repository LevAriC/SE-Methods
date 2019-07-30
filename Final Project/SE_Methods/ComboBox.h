#pragma once
#include "Control.h"
class ComboBox :public Control
{
private:
	vector<string> values;
	string textBox;
	bool isOpen;
	int currentIndex;
	int width;
	int selectedIndex;
public:
	ComboBox(Border*, short, short, vector<string>);
	ComboBox(Border*, short, short, vector<string>, Color, Color);
	void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
	void keyDown(int, char, Graphics&);
	void onFocus(bool) {};
	bool canGetFocus();
	bool isControlsList();
	bool isLastIndex();
	int getWidth();
};