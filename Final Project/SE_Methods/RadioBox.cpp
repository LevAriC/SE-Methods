#include "RadioBox.h"
#include <iostream>

RadioItem::RadioItem(short left, short top, string str) :Control(left, top), text(str), isSelected(FALSE) {}
bool RadioItem::canGetFocus() { return TRUE; };
bool RadioItem::isControlsList() { return TRUE; };
bool RadioItem::getIsSelected() { return isSelected; }

void RadioItem::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.moveTo(x, y);
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);

	cout << '\xDA' << '\xC4' << '\xC4' << '\xC4' << '\xBF';

	for (int i = 0; i < text.size() + 2; i++)
		cout << ' ';

	graphics.moveTo(x, y + 1);
	cout << '\xB3' << ' ' << ' ' << ' ' << '\xB3' << ' ';

	graphics.moveTo(x, y + 2);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xC4' << '\xD9';

	for (int i = 0; i < text.size() + 2; i++)
		cout << ' ';

	if (isSelected)
		graphics.write(x + 2, y + 1, "O");

	graphics.moveTo(x + 6, y + 1);
	graphics.write(text);
	cout << ' ';
}

void RadioItem::setIsSelected()
{
	if (!isSelected)
		isSelected = TRUE;
	else
		isSelected = FALSE;
}

void RadioItem::mousePressed(int x, int y, bool isMousePressed)
{
	if ((x > left && x < (left + text.size())))
	{
		isSelected = TRUE;
	}
}

bool RadioBox::canGetFocus() { return TRUE; };
bool RadioBox::isControlsList() { return TRUE; }

RadioBox::RadioBox(Border* border, short left, short top, vector<string> values) : Control(left, top, border), currentCboxIndex(-1), selectedIndex(0) , lastSelected(-1)
{
	for (int i = 0; i < values.size(); i++) {
		RadioItemsList.push_back(new RadioItem(left + 2, 1 + (i * 3), values[i]));
		COORD pos = { left + (short)4  , top + (short)(2 + (i * 3)) };
		checkBoxCoord.push_back(pos);
	}
}

void RadioBox::draw(Graphics& graphics, int x, int y, size_t z)
{
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	border->createBorder(graphics, x, y, 25, static_cast<int>(RadioItemsList.size() * 4));

	for (RadioItem* item : RadioItemsList)
		item->draw(graphics, item->getLeft(), y + item->getTop(), z);
}

void RadioBox::keyDown(int keyCode, char charecter, Graphics& graphics)
{
	int vectorSize = RadioItemsList.size();
	
	switch (keyCode)
	{
		case VK_TAB:
			if (++currentCboxIndex == 0)
			{
				selectedIndex = currentCboxIndex;
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
			}
			else if (currentCboxIndex == vectorSize - 1)
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
		break;

		case VK_DOWN:
			if (++currentCboxIndex == 1)
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == 0)
			{
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == vectorSize)
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[0]->changeFocusedColor();
				currentCboxIndex = 0;
				selectedIndex = currentCboxIndex;
			}
			else
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
		break;

		case VK_NUMPAD2:
			if (++currentCboxIndex == 1)
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == 0)
			{
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == vectorSize)
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[0]->changeFocusedColor();
				currentCboxIndex = 0;
				selectedIndex = currentCboxIndex;
			}
			else
			{
				RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
		break;

		case VK_UP:
			if (--currentCboxIndex == 0)
			{
				RadioItemsList[currentCboxIndex + 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex <= -1)
			{
				currentCboxIndex = vectorSize - 1;
				RadioItemsList[0]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else
			{
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				RadioItemsList[currentCboxIndex + 1]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
		break;

		case VK_NUMPAD8:
			if (--currentCboxIndex == 0)
			{
				RadioItemsList[currentCboxIndex + 1]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex <= -1)
			{
				currentCboxIndex = vectorSize - 1;
				RadioItemsList[0]->changeFocusedColor();
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
			else
			{
				RadioItemsList[currentCboxIndex]->changeFocusedColor();
				RadioItemsList[currentCboxIndex + 1]->changeFocusedColor();
				selectedIndex = currentCboxIndex;
			}
		break;

		case VK_SPACE:
			if (lastSelected == -1)
			{
				lastSelected = selectedIndex;
				RadioItemsList[selectedIndex]->setIsSelected();
			}
			else
			{
				RadioItemsList[lastSelected]->setIsSelected();
				RadioItemsList[selectedIndex]->setIsSelected();
				lastSelected = selectedIndex;
			}
		break;
	}
}

bool RadioBox::isLastIndex()
{
	int vectorSize = RadioItemsList.size();

	if (++currentCboxIndex == 0)
	{
		selectedIndex = currentCboxIndex;
		RadioItemsList[currentCboxIndex]->changeFocusedColor();
		return FALSE;
	}
	else if (currentCboxIndex == vectorSize - 1)
	{
		RadioItemsList[currentCboxIndex]->changeFocusedColor();
		RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
		currentCboxIndex = vectorSize - 1;
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
	else if (currentCboxIndex == vectorSize)
	{
		RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
		currentCboxIndex = -1;
		return TRUE;
	}
	else
	{
		RadioItemsList[currentCboxIndex - 1]->changeFocusedColor();
		RadioItemsList[currentCboxIndex]->changeFocusedColor();
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
}
