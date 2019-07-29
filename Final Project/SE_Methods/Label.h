#pragma once

#include "Control.h"

class Label : public Control
{
	string value;

public:
	Label(short, short, string);
	void draw(Graphics&, int, int);
};

