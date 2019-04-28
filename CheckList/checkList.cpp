#include "checkList.h"

Checklist::Checklist(vector<string> options, int X, int Y) {

	this->size = options.size();
	this->HandleOutPut = GetStdHandle(STD_OUTPUT_HANDLE);
	this->list = new Checkbox[this->size];
	this->listPosition.X = X;
	this->listPosition.Y = Y;
	this->current = 0 ;

	if (this->list == nullptr) {
		exit(0);
	}

	for (int i = 0; i < this->size; ++i) {
		this->list[i].setText(options[i]);
		this->list[i].setPositionX(X);
		this->list[i].setPositionY(Y + i);
		this->list[i].setKeyboardPos(false);
	}
	this->list[0].setKeyboardPos(true);
}

Checklist::~Checklist() {
	delete[] this->list;
}


void Checklist::drawList() {
	SetConsoleCursorPosition(HandleOutPut, listPosition);
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(HandleOutPut, &consoleScreenBufferInfo);

	CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
	SetConsoleCursorInfo(HandleOutPut, &consoleCursorInfo);

	for (int i = 0; i < size; ++i) {
		if(i == current) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		SetConsoleCursorPosition(HandleOutPut, this->list[i].getCoordinate());
		this->list[i].drawLine();
	}
}

void Checklist::inputHandler(INPUT_RECORD input) {

	if (input.EventType == KEY_EVENT) 
		this->KeyEvent(input.Event.KeyEvent);
	else 
		MouseEvent(input.Event.MouseEvent);
}

void Checklist::KeyEvent(KEY_EVENT_RECORD Event) {
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(HandleOutPut, &consoleScreenBufferInfo);

	if (Event.bKeyDown == true) {
		for (int i = 0; i < this->size; ++i) {
			if (this->list[i].getKeyboardPos() == true) {
				item = &this->list[i];
				current = i;
				SetConsoleCursorPosition(HandleOutPut, this->list[current].getCoordinate());
				this->list[current].mark(false);
				break;
			}
		}
		if (item == nullptr) {
			return;
		}
		if (Event.wVirtualKeyCode == VK_DOWN) {
			item->setKeyboardPos(false);
			if (current == this->size - 1) {
				item = &this->list[0];
				item->setKeyboardPos(true);
				current = 0;
			}
			else {
				++current;
				item = &this->list[current];
				item->setKeyboardPos(true);

			}
			SetConsoleCursorPosition(HandleOutPut, this->list[current].getCoordinate());
			this->list[current].mark(true);
			return;
		}
		if (Event.wVirtualKeyCode == VK_UP) {
			item->setKeyboardPos(false);
			if (current == 0) {
				current = this->size - 1;
				this->list[current].setKeyboardPos(true);
			}
			else {
				--current;
				this->list[current].setKeyboardPos(true);
			}
			SetConsoleCursorPosition(HandleOutPut, this->list[current].getCoordinate());
			this->list[current].mark(true);
			return;
		}	
		if (Event.wVirtualKeyCode == VK_SPACE) {
			SetConsoleCursorPosition(HandleOutPut, this->list[current].getCoordinate());
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			this->list[current].changeMode();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

			return;
		}
	}
}


void Checklist::MouseEvent(MOUSE_EVENT_RECORD Event) {
	COORD mCords = Event.dwMousePosition;

	if (Event.dwEventFlags == 0) {
		if (Event.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			for (int i = 0; i < this->size; ++i) {
				if (this->list[i].isTarget(mCords)) {
					this->list[current].setKeyboardPos(false) ; 
					current = i ;
					this->list[i].setKeyboardPos(true) ;
					SetConsoleCursorPosition(HandleOutPut, this->list[i].getCoordinate());
					this->list[i].changeMode();
					drawList();
					break;
				}

			}
		}
	}
}