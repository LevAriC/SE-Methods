#include "Panel.h"

Panel::Panel(Border* border, short left, short top, short width, short height) : Control(left, top, border)
{
	this->width = width;
	this->height = height;
}

bool Panel::canGetFocus() { return TRUE; }
void Panel::getAllControls(vector<Control*>* controls) { *controls = this->controlsList; }
void Panel::pushToControlsList(Control* control) { controlsList.push_back(control); }
void Panel::setWidth(short width) { this->width = width; }
void Panel::setHeight(short height) { this->height = height; }

void Panel::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	border->createBorder(graphics, x, y, width , height);

	for (Control* control : controlsList)
		control->draw(graphics, control->getLeft(), control->getTop(), z);
}

void Panel::mousePressed(int x, int y, bool isMousePressed)
{
	for (Control* control : controlsList)
	{
		int _x = control->getLeft();
		int _y = control->getTop();
		int _width = control->getWidth();

		if (control->canGetFocus() && (y == _y && (x > _x && x < (_x + _width - 1))))
		{
			Control::setFocus(*control);
			control->mousePressed(x, y, isMousePressed);
			break;
		}
		else if (!(control->canGetFocus()) && (y == _y && (x > left && x < (_x + _width - 1))))
		{
			control->mousePressed(x, y, isMousePressed);
			break;
		}
	}
}

void Panel::initPanelFocus()
{
	if (controlsList.size() > 0) {
		if (controlsList[0]->canGetFocus())
		{
			Control& tmp = *controlsList[0];
			Control::setFocus(tmp);
		}
	}
}