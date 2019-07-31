#include "Label.h"

Label::Label(Border* border, short left, short top, string value) : Control(left, top, border), value(value) {}
Label::Label(Border* border, short left, short top, string value, Color backgroundColor, Color foregroundColor) : Control(left, top, border), value(value)
{
	this->setBackgroundColor(backgroundColor);
	this->setForegroundColor(foregroundColor);
}

void Label::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	border->createBorder(graphics, x, y, value.size() + 2, 4);
	graphics.moveTo(x + 1, y + 1);
	graphics.write(value);
}