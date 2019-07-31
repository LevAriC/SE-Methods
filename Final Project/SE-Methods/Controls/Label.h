#pragma once

#include "../Common/Control.h"

class Label : public Control
{
	string value;

public:
	Label(Border*, short, short, string);
	Label(Border*, short, short, string, Color, Color);
	void draw(Graphics&, int, int, size_t);
};

