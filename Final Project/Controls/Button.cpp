#include "Button.h"
#include "Control.h"

int Button::getWidth()  { return width; }
void Button::PushToControlsList(Control* control) { controlsList.push_back(control); }

Button::Button(Border* border, short left, short top, string text) : Control(left, top, border), text(text), isTriggered(FALSE)
{
	this->width = TXTSIZE;
}

Button::Button(Border* border, short left, short top, string text, Color backgroundColor, Color foregroundColor) : Control(left, top, border), text(text), isTriggered(FALSE)
{
	this->setBackgroundColor(backgroundColor);
	this->setForegroundColor(foregroundColor);
	this->width = TXTSIZE;
}

void Button::mousePressed(int x, int y, bool isMousePressed)
{
	if (isMousePressed && (y == top && (x > left && x < (left + TXTSIZE))))
	{
		if (!isTriggered)
			isTriggered = TRUE;
		else
			isTriggered = FALSE;

		for (int i = 0; i < controlsList.size(); i++)
			controlsList[i]->buttonEvent();
	}
}

void Button::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	border->createBorder(graphics, x, y, TXTSIZE, 4);
	graphics.setCursorVisibility(FALSE);
	graphics.moveTo(x + 1, y + 1);
	graphics.write(text);
}
