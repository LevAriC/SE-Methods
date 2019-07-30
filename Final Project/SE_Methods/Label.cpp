#include "Label.h"

Label::Label(short left, short top , string value) : Control(left , top) , value(value) {}
Label::Label(short left, short top, string value, Color backgroundColor, Color foregroundColor) : Control(left, top), value(value)
{
	this->setBackgroundColor(backgroundColor);
	this->setForegroundColor(foregroundColor);
}

void Label::draw(Graphics& graphics, int x, int y, size_t z)
{
	//graphics.moveTo(x, y);
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	graphics.moveTo(x + 2, y + 1);
	graphics.write(value);
}