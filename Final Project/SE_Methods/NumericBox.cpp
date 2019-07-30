#include "NumericBox.h"
#include <iostream>

using namespace std;

int NumericBox::getWidth() { return this->width; };

NumericBox::NumericBox(Border* border, short left, short top, int min, int max) : Control(left, top, border) , minNum(min), maxNum(max), value(0) , width(17)
{
	if(max < min)
	{
		int tmp = max;
		max = min;
		min = tmp;
	}
	if (max < 0)
		value = min;
	else if (min > 0)
		value = max;
}
NumericBox::NumericBox(Border* border, short left, short top, int min, int max, Color backgroundColor, Color foregroundColor) : Control(left, top, border), minNum(min), maxNum(max), value(0), width(17)
{
	if (max < min)
	{
		int tmp = max;
		max = min;
		min = tmp;
	}
	if (max < 0)
		value = min;
	else if (min > 0)
		value = max;

	this->setBackgroundColor(backgroundColor);
	this->setForegroundColor(foregroundColor);
}


void NumericBox::draw(Graphics& graphics, int x, int y, size_t z)
{
	border->createBorder(graphics, left, top, this->width + 4, 6);

	graphics.moveTo(left + 2, top + 1);
	cout << '\xDA' << '\xC4' << '\xC4' << '\xC4' << '\xBF';
	graphics.moveTo(left + 2, top + 2);
	cout << '\xB3' << ' ' << ' ' << ' ' << '\xB3' << ' ';
	graphics.moveTo(left + 2, top + 3);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xC4' << '\xD9';
	graphics.moveTo(left + 3, top + 2);
	cout << ' ' << '-' << ' ';

	graphics.moveTo(left + this->width - 3, top + 1);
	cout << '\xDA' << '\xC4' << '\xC4' << '\xC4' << '\xBF';
	graphics.moveTo(left + this->width - 3, top + 2);
	cout << '\xB3' << ' ' << ' ' << ' ' << '\xB3' << ' ';
	graphics.moveTo(left + this->width - 3, top + 3);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xC4' << '\xD9';
	graphics.moveTo(left + this->width - 2, top + 2);
	cout << ' ' << '+' << ' ';

	graphics.write(left + 2 + (this->width / 2), top + 2, to_string(value));
}

void NumericBox::mousePressed(int x, int y, bool isMousePressed)
{
	if ((y == top) && (x > (left-2) && x < (left+4)))
	{
		if (value > minNum)
			value--;
	}
	else if((y == top) && (x >= (left + 12) && x <= left + 21))
	{
		if (value < maxNum)
			value++;
	}
}
