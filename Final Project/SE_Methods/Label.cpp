#include "Label.h"

Label::Label(short left, short top , string value) : Control(left , top) , value(value) {}

void Label::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.moveTo(x, y);
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	graphics.moveTo(x + 3, y + 1);
	graphics.write(value);
}