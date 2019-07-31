#include "CheckList.h"
#include <iostream>
using namespace std;

bool CheckList::canGetFocus() { return TRUE; }
bool CheckList::isControlsList() { return TRUE; }
void CheckList::onFocus(bool flag) { focus = flag; }
CheckBox::CheckBox(short CBleft, short CBtop, string CBvalue) : Control(CBleft, CBtop), value(CBvalue), isSelected(FALSE) {}

bool CheckBox::getSelected() { return isSelected; }
bool CheckBox::getFocus() { return TRUE; }

CheckList::CheckList(Border* border, short left, short top, vector<string> values, Color backgroundColor = Color::Black, Color foregroundColor = Color::White) : Control(left, top, border), focusedCheckBox(-1), selectedIndex(0)
{
	this->setBackgroundColor(backgroundColor);
	this->setForegroundColor(foregroundColor);

	for (short i = 0; i < values.size(); i++) {
		checkBoxList.push_back(new CheckBox(left + 2, 1 + (i * 3), values[i]));
		checkBoxList[i]->setBackgroundColor(this->getBackgroundColor());
		checkBoxList[i]->setForegroundColor(this->getForegroundColor());
		checkBoxLocation.push_back({ left + 2  , 1 + (i * 3) });
	}
}

void CheckList::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	border->createBorder(graphics, x, y, 25, checkBoxList.size() * 4);
	for (CheckBox* c : checkBoxList)
		c->draw(graphics, c->getLeft() , y + c->getTop(), z);
}

void CheckList::mousePressed(int x, int y, bool isMousePressed)
{
	for (CheckBox* c : checkBoxList) {
		if (y > c->getTop() && y < c->getTop() + 5  && (x > c->getLeft()-1 && x < c->getLeft()+2))
			c->setSelected();
	}
}

void CheckList::keyDown(int keyCode, char charecter , Graphics & g)
{
	int vectorSize = checkBoxList.size();	
	switch (keyCode)
	{
		case VK_TAB:
			if (++focusedCheckBox == 0)
			{
				selectedIndex = focusedCheckBox;
				checkBoxList[focusedCheckBox]->changeFocusedColor();
			}
			else if (focusedCheckBox == vectorSize -1)
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}	
			else
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			break;

		case VK_DOWN:
			if (++focusedCheckBox == 1)
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else if (focusedCheckBox == 0)
			{
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else if (focusedCheckBox == vectorSize)
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[0]->changeFocusedColor();
				focusedCheckBox = 0;
				selectedIndex = focusedCheckBox;
			}
			else
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			break;

		case VK_NUMPAD2:
			if (++focusedCheckBox == 1)
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else if (focusedCheckBox == 0)
			{
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else if (focusedCheckBox == vectorSize)
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[0]->changeFocusedColor();
				focusedCheckBox = 0;
				selectedIndex = focusedCheckBox;
			}
			else
			{
				checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			break;

		case VK_UP:
			if (--focusedCheckBox == 0)
			{
				checkBoxList[focusedCheckBox + 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else if (focusedCheckBox <= -1)
			{
				focusedCheckBox = vectorSize - 1;
				checkBoxList[0]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else
			{
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				checkBoxList[focusedCheckBox + 1]->changeFocusedColor();	
				selectedIndex = focusedCheckBox;
			}
			break;

		case VK_NUMPAD8:
			if (--focusedCheckBox == 0)
			{
				checkBoxList[focusedCheckBox + 1]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else if (focusedCheckBox <= -1)
			{
				focusedCheckBox = vectorSize - 1;
				checkBoxList[0]->changeFocusedColor();
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			else
			{
				checkBoxList[focusedCheckBox]->changeFocusedColor();
				checkBoxList[focusedCheckBox + 1]->changeFocusedColor();
				selectedIndex = focusedCheckBox;
			}
			break;

		case VK_SPACE:
			checkBoxList[selectedIndex]->setSelected();
			break;
	}
}

bool CheckList::isLastIndex()
{	
	int vectorSize = checkBoxList.size();
	if (++focusedCheckBox == 0)
	{
		selectedIndex = focusedCheckBox;
		checkBoxList[focusedCheckBox]->changeFocusedColor();
		return FALSE;
	}
	else if (focusedCheckBox == vectorSize - 1)
	{
		checkBoxList[focusedCheckBox]->changeFocusedColor();
		checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
		focusedCheckBox = vectorSize - 1;
		selectedIndex = focusedCheckBox;
		return FALSE;
	}
	else if (focusedCheckBox == vectorSize)
	{
		checkBoxList[vectorSize - 1]->changeFocusedColor();
		focusedCheckBox = - 1;
		return TRUE;
	}
	else
	{
		checkBoxList[focusedCheckBox - 1]->changeFocusedColor();
		checkBoxList[focusedCheckBox]->changeFocusedColor();
		selectedIndex = focusedCheckBox;
		return FALSE;
	}
}

void CheckBox::setSelected()
{
	if (!isSelected)
		isSelected = TRUE;
	else
		isSelected = FALSE;
}

void CheckBox::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.moveTo(x, y);
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);

	cout << '\xDA' << '\xC4' << '\xC4' << '\xC4' << '\xBF';

	for (int i = 0; i < value.size() + 2; i++)
		cout << ' ';

	graphics.moveTo(x, y + 1);
	cout << '\xB3' << ' ' << ' ' << ' ' << '\xB3' << ' ';

	graphics.moveTo(x, y + 2);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xC4' << '\xD9';

	for (int i = 0; i < value.size() + 2; i++)
		cout << ' ';

	if (isSelected)
		graphics.write(x + 2, y + 1, "X");

	graphics.moveTo(x + 6, y + 1);
	graphics.write(value);
	cout << ' ';
}