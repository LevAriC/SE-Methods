#pragma once

#include "Control.h"

class Panel : public Control
{
	vector<Control*> controlsList;
	short width;
	short height;

public:
	Panel(Border*, short, short);

	void initPanelFocus();
	void setWidth(short);
	void setHeight(short);
	void draw(Graphics&, int, int, size_t);
	void mousePressed(int, int, bool);
	void getAllControls(vector<Control*>*);
	void pushToControlsList(Control*);
	bool canGetFocus();
};

