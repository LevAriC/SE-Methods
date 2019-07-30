#pragma once
#include "Control.h"

class CheckBox : public Control
{
	string value;
	bool isSelected;

public:
	CheckBox(short, short, string);
	CheckBox(short, short, string, Color, Color);
	bool getSelected();
	void setSelected();
	void draw(Graphics&, int, int, size_t);
	bool getFocus();
};

class CheckList : public Control
{
	vector<CheckBox*> checkBoxList;
	vector<COORD> checkBoxLocation;
	int focusedCheckBox;
	int selectedIndex;
	bool focus;

public:
	CheckList(Border*, short, short, vector<string>);
	CheckList(Border*, short, short, vector<string>, Color, Color);
	void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
	void keyDown(int, char, Graphics&);
	bool canGetFocus();
	bool isControlsList();
	bool isLastIndex();
	void onFocus(bool);
};
