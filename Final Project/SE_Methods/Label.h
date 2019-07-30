#pragma once

#include "Control.h"

class Label : public Control
{
	string value;

public:
	Label(short, short, string);
	Label(short, short, string, Color, Color);
	void draw(Graphics&, int, int, size_t);
};

