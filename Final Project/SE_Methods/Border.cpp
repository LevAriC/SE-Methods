#include "Border.h"
#include <iostream>

using namespace std;

void SingleBorder::createBorder(Graphics& graphics, short left, short top, short width, short height)
{
	graphics.moveTo(left, top);

	cout << '\xDA';
	for (int i = 0; i < width - 2; i++) 
		cout << '\xC4';
	cout << '\xBF';

	graphics.moveTo(left, top + 1);

	int _temp = top + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << '\xB3';
		for (int y = 0; y < width - 2; y++)
			cout << ' ';
		cout << '\xB3';

		graphics.moveTo(left, _temp++);
	}

	graphics.moveTo(left, top + height - 2);
	cout << '\xC0';
	graphics.moveTo(left + 1, top + height - 2);
	for (int i = 0; i < width - 2; i++) 
		cout << '\xC4';
	cout << '\xD9';
}

void DoubleBorder::createBorder(Graphics& graphics, short left, short top, short width, short height)
{
	graphics.moveTo(left, top);

	cout << '\xC9';
	for (int i = 0; i < width - 2; i++)
		cout << '\xCD';
	cout << '\xBB';	

	graphics.moveTo(left, top + 1);

	int _temp = top + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << '\xBA';									
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << '\xBA';									
		graphics.moveTo(left, _temp++);
	}

	graphics.moveTo(left, top + height - 2);
	cout << '\xC8';						
	graphics.moveTo(left + 1, top + height - 2);
	for (int i = 0; i < width - 2; i++) 
		cout << '\xCD';				
	cout << '\xBC';						
}

