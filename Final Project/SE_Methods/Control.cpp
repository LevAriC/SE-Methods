#include "Control.h"

Control* Control::focusedControl = NULL;
Control::Control(short left, short top) : left(left), top(top), backgroundColor(Color::Black), foregroundColor(Color::White), border(NULL) {};
Control::Control(short left, short top, Border* border) : left(left), top(top), backgroundColor(Color::Black), foregroundColor(Color::White), border(border) {};
Control* Control::getFocus() { return focusedControl; }
void Control::setBackgroundColor(Color backgroundColor) { this->backgroundColor = backgroundColor; }
void Control::setForegroundColor(Color foregroundColor) { this->foregroundColor = foregroundColor; }
Color Control::getBackgroundColor() { return this->backgroundColor; }
Color Control::getForegroundColor() { return this->foregroundColor; }

void Control::setBorder(Border* border) { this->border = border; }
void Control::setWidth(int) { this->width = width; }
int Control::getWidth() { return width; }
bool Control::isControlsList() { return FALSE; };
short Control::getLeft() { return this->left; }
short Control::getTop() { return this->top; }
bool Control::canGetFocus() { return FALSE; }
bool Control::isLastIndex() { return TRUE; }
bool Control::setFocus(Control& control)
{
	if (focusedControl != NULL)
	{
		if (!control.isControlsList())
		{
			focusedControl->onFocus(FALSE);
			focusedControl = &control;
			control.onFocus(TRUE);
			return TRUE;
		}
		focusedControl->onFocus(FALSE);
		focusedControl = &control;
		control.onFocus(TRUE);
		return TRUE;
	}
	focusedControl = &control;
	control.onFocus(TRUE);
	return TRUE;
}

void Control::changeFocusedColor()
{
	Color tmp = backgroundColor;
	backgroundColor = foregroundColor;
	foregroundColor = tmp;
}
