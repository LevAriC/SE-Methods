#pragma once
#include "Label.h"
#define TXTSIZE text.size() + 2

class Button : public Control {
	vector <Control*> controlsList;
	string text;
	bool isTriggered;
	int width;
	int height;

public:
	Button(Border*, short, short, string);
	int getWidth();
	void mousePressed(int, int, bool);
	void PushToControlsList(Control*);
	void draw(Graphics&, int, int, size_t);
};
