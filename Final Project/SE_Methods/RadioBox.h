#pragma once
#include "Control.h"

class RadioItem : public Control
{
	string text;
	bool isSelected;

public:
	RadioItem(short, short, string);
	void draw(Graphics&, int, int, size_t);
	void setIsSelected();
	bool canGetFocus();
	bool isControlsList();
	bool getIsSelected();
	void mousePressed(int, int, bool);
};

class RadioBox : public Control
{
	vector<RadioItem*> RadioItemsList;
	vector<COORD> checkBoxCoord;
	bool focus;
	int currentCboxIndex;
	int selectedIndex;
	int lastSelected;

public:
	RadioBox(Border*, short, short, vector<string>);
	void draw(Graphics&, int, int, size_t);
	//void mousePressed(int, int, bool);
	void keyDown(int, char, Graphics&);
	bool canGetFocus();
	bool isControlsList();
	bool isLastIndex();
};

