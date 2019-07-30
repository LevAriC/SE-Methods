#include "NumericBox.h"
#include <iostream>

using namespace std;

NumericBox::NumericBox(Border* border, short left, short top, int min, int max) : Control(left, top, border) , minNum(min), maxNum(max), value(0) , width(17) {}
int NumericBox::getWidth() { return this->width; };

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

	graphics.moveTo(this->width - 1, top + 1);
	cout << '\xDA' << '\xC4' << '\xC4' << '\xC4' << '\xBF';
	graphics.moveTo(this->width - 1, top + 2);
	cout << '\xB3' << ' ' << ' ' << ' ' << '\xB3' << ' ';
	graphics.moveTo(this->width - 1, top + 3);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xC4' << '\xD9';
	graphics.moveTo(this->width, top + 2);
	cout << ' ' << '+' << ' ';

	graphics.write(left + 10, top + 2, to_string(value));
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
