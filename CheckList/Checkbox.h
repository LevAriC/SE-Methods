#include <string>
#include <Windows.h>
#include <sstream>
#include <iostream>

using namespace std;

class Checkbox {
	private:
		HANDLE H_OutPut;
		COORD position;
		string text;
		int length;
		bool clicked;
		bool KeyBoardPos;

	public:
		Checkbox(string text, int x, int y);
		Checkbox();
		void drawLine();
		void mark(bool toMark);
		void changeMode();
		bool isTarget(COORD mouseCordinate);
		void setText(string text);
		void setPositionX(int x);
		void setPositionY(int y);
		COORD getCoordinate();
		bool getCheckedStatus();
		void setKeyboardPos(bool whereIn);
		bool getKeyboardPos();
};