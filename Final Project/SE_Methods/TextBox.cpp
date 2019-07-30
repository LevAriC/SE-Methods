#include "TextBox.h"
#include <iostream>
#include <string>

using namespace std;

TextBox::TextBox(Border* border, short left, short top, int width, int height) : Control(left, top, border), width(width), height(height), cursor(0), isFocused(FALSE), text() {}
void TextBox::onFocus(bool isFocused) { this->isFocused = isFocused; }
bool TextBox::canGetFocus() { return TRUE; };
int TextBox::getWidth() { return this->width; };

void TextBox::keyDown(int keyCode, char character, Graphics& graphics)
{
	graphics.moveTo(text.size() + (left + 1), top + 1);

	if (character > 0)
	{
		if ((width - 2) > text.size() && (character >= 65 && character <= 90 || character >= 97 && character <= 122 || character >= 48 && character <= 57 || character == 32))
		{
			if (cursor < text.size())
			{
				if (character == 32)
					text.replace(text.begin() + cursor, text.end() - (text.size() - cursor), 1, character);
				else
				{
					text.replace(text.begin() + cursor, text.end() - (text.size() - cursor), 1, character);
					cursor++;
				}
			}
			else
			{
				text.push_back(character);
				cursor = static_cast<int>(text.size());
			}

		}
	}
	else
	{
		switch (keyCode)
		{
		case VK_DELETE:
			if (cursor > 0)
			{
				text.erase(text.begin() + (cursor - 1));
				--cursor;
			}
			break;
		case VK_BACK:
			if (cursor > 0)
			{
				text.erase(text.begin() + (cursor - 1));
				--cursor;
			}
		case VK_LEFT:
			if (cursor > 0)
				--cursor;
			break;
		case VK_NUMPAD4:
			if (cursor > 0)
				--cursor;
		case VK_RIGHT:
			if (cursor < text.size())
				++cursor;
			break;
		case VK_NUMPAD6:
			if (cursor < text.size())
				++cursor;
			break;
		}
	}
}

void TextBox::mousePressed(int x, int y, bool isMousePressed)
{
	if (y == top && (x > left && x < (left + width - 1)))
	{
		if (x > text.size())
			cursor = text.size();
		else
			cursor = (x - (left + 1));
	}
}

void TextBox::draw(Graphics& graphics, int x, int y, size_t size)
{
	if (isFocused)
	{
		this->border->createBorder(graphics, x, y, this->width, this->height);
		graphics.write(x + 1, y + 1, text);
		graphics.moveTo(cursor + (left + 1), top + 1);
		graphics.setCursorVisibility(TRUE);
		graphics.write("_");
	}
	else
	{
		this->border->createBorder(graphics, x, y, this->width, this->height);
		graphics.setCursorVisibility(FALSE);
		graphics.write(x + 1, y + 1, text);
	}

}
