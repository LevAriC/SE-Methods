#pragma once
#include "Label.h"
#define TXTSIZE text.size() + 2

class Button : public Control {
	vector <Control*> controlsList;
	string text;
	int width;
	int height;
	bool isTriggered;

public:
	Button(Border*, short, short, string);
	Button(Border*, short, short, string, Color, Color);
	int getWidth();
	void mousePressed(int, int, bool);
	void PushToControlsList(Control*);
	void draw(Graphics&, int, int, size_t);
	//bool getIsTriggered();
	//void setIsTriggered(bool);
};
