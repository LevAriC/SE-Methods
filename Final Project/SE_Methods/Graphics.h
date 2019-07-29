#pragma once

#include <string>
#include <windows.h>

using namespace std;

enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White };

class Graphics
{
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen();
	void moveTo(int, int);
	void setBackground(Color);
	void setForeground(Color);
	void write(string);
	void write(int, int, string);
	void write(wstring);
	void write(int, int, wstring);
	void setCursorVisibility(bool);
private:
	HANDLE _console;
	Color _background, _foreground;

	void updateConsoleAttributes();
};
// Needs Attention
//bool isInside(int x, int y, int left, int top, int width, int height);
