#include "ComboBox.h"
#include <iostream>

using namespace std;

bool ComboBox::canGetFocus() { return TRUE; }
bool ComboBox::isControlsList() { return TRUE; }
int ComboBox::getWidth() { return width; }

ComboBox::ComboBox(Border* border, short left, short top, vector<string> values) : Control(left, top, border), values(values), width(18), isOpen(FALSE), currentIndex(0) { textBox = values[0]; }

ComboBox::ComboBox(Border* border, short left, short top, vector<string> values, Color backgroundColor, Color foregroundColor) : Control(left, top, border), values(values), width(18), isOpen(FALSE), currentIndex(0)
{
	this->setBackgroundColor(backgroundColor);
	this->setForegroundColor(foregroundColor);
	textBox = values[0];
}

void ComboBox::draw(Graphics& graphics, int x, int y, size_t size)
{
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);
	graphics.moveTo(x, y);

	if (!isOpen)
	{
		cout << '\xDA';
		for (int i = 0; i < this->width; i++)
			cout << '\xC4';
		cout << '\xBF';
		graphics.moveTo(x, y + 1);
		cout << '\xB3';
		for (int i = 0; i < this->width-1; i++)
			cout << ' ';
		cout << 'v' << '\xB3';
		graphics.write(x + 2, y + 1, textBox);
		graphics.moveTo(x, y + 2);
		cout << '\xC0';
		for (int i = 0; i < this->width; i++)
			cout << '\xC4';
		cout << '\xD9';
	}
	else
	{
		cout << '\xDA';
		for (int i = 0; i < this->width; i++)
			cout << '\xC4';
		cout << '\xBF';
		graphics.moveTo(x, y + 1);
		cout << '\xB3';
		for (int i = 0; i < this->width-1; i++)
			cout << ' ';
		cout << '^' << '\xB3';
		graphics.write(x + 2, y + 1, values[0]);
		graphics.moveTo(x, y + 2);
		cout << '\xB3';
		for (int i = 0; i < this->width; i++)
			cout << '\xC4';
		cout << '\xB3';

		int tempX = x;
		int tempY = y + 3;

		for (int y = 0; y < values.size(); y++)
		{
			graphics.setBackground(backgroundColor);
			graphics.setForeground(foregroundColor);
			if (y == currentIndex)
			{
				graphics.setBackground(Color::White);
				graphics.setForeground(Color::Black);
			}
			if (y == values.size() - 1)
			{
				graphics.moveTo(tempX, tempY);
				cout << '\xB3';
				for (int x = 0; x < this->width; x++)
					cout << ' ';
				cout << '\xB3';
				graphics.write(tempX + 2, tempY, values[y]);
				graphics.moveTo(tempX, ++tempY);
				cout << '\xC0';
				for (int x = 0; x < this->width; x++)
					cout << '\xC4';
				cout << '\xD9';
			}
			else
			{
				graphics.moveTo(tempX, tempY);
				cout << '\xB3';
				for (int x = 0; x < this->width; x++)
					cout << ' ';
				cout << '\xB3';
				graphics.write(tempX + 2, tempY, values[y]);
				graphics.moveTo(tempX, ++tempY);
				cout << '\xB3';
				for (int x = 0; x < this->width; x++)
					cout << '\xC4';
				cout << '\xB3';
				tempY++;
			}

		}
	}
}

void ComboBox::mousePressed(int x, int y, bool isMousePressed)
{
	if (y == top && (x > left && x < (left + this->width+1)))
	{
		if (!isOpen)
		{
			isOpen = !isOpen;
			currentIndex = 0;
		}
		else
		{
			isOpen = !isOpen;
			currentIndex = 0;
		}
	}
}

void ComboBox::keyDown(int keyCode, char character, Graphics & g)
{
	int vectorSize = values.size();
	switch (keyCode)
	{
	case VK_TAB:

		break;
	case VK_DOWN:
		if(currentIndex == vectorSize -1)
			currentIndex = 0;
		else
			currentIndex++;
		break;
	case VK_NUMPAD2:
		if (currentIndex == vectorSize - 1)
			currentIndex = 0;
		else
			currentIndex++;
		break;
	case VK_UP:
		if (currentIndex == 0)
			currentIndex = vectorSize - 1;
		else
			currentIndex--;
		break;
	case VK_NUMPAD8:
		if (currentIndex == 0)
			currentIndex = vectorSize - 1;
		else
			currentIndex--;
		break;
	case VK_SPACE:
		textBox = values[currentIndex];
		isOpen = !isOpen;
		break;
	case VK_RETURN:
		textBox = values[currentIndex];
		isOpen = !isOpen;
		break;
	}
}

bool ComboBox::isLastIndex()
{
	int vectorSize = static_cast<int>(values.size());

	if (currentIndex == vectorSize)
	{
		currentIndex = 1;
		isOpen = !isOpen;
		return TRUE;
	}
	else
	{
		currentIndex++;
		return FALSE;
	}
}