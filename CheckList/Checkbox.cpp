#include "Checkbox.h"

Checkbox::Checkbox(string text, int x, int y) {
	this->position.X = x;
	this->position.Y = y;
	this->text = text;
	this->length = text.length() + 1;
	this->clicked = false;
	this->H_OutPut = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Checkbox::drawLine() {
	SetConsoleCursorPosition(this->H_OutPut, this->position);
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(this->H_OutPut, &consoleScreenBufferInfo);

	CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
	SetConsoleCursorInfo(this->H_OutPut, &consoleCursorInfo);

	if (this->clicked == true) {
		cout << "[o]" << this->text;
	}
	else {
		cout << "[ ]" << this->text;
	}

}

void Checkbox::mark(bool toMark=true){

	SetConsoleCursorPosition(this->H_OutPut, this->position);
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(this->H_OutPut, &consoleScreenBufferInfo);

	CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
	SetConsoleCursorInfo(this->H_OutPut, &consoleCursorInfo);

	if(toMark)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	if (this->clicked == true) {
		cout << "[o]" << this->text;
	}
	else {
		cout << "[ ]" << this->text;
	}

}

void Checkbox::changeMode() {
	if (this->clicked == true) {
		this->clicked = false;
		this->mark();
	}
	else {
		this->clicked = true;
		this->mark();
	}
}

void Checkbox::setPositionX(int x) {
	this->position.X = x;
}

void Checkbox::setPositionY(int y) {
	this->position.Y = y;
}

void Checkbox::setText(string text) {
	this->text = text;
	this->length = text.length() +1;
}

bool Checkbox::isTarget(COORD mouseCordinate) {
	if (mouseCordinate.Y == this->position.Y && mouseCordinate.X > this->position.X && mouseCordinate.X < this->position.X + this->length + 3) {
		return true;
	}
	return false;
}

COORD Checkbox::getCoordinate() {
	return this->position;
}

bool Checkbox::getCheckedStatus() {
	return this->clicked;
}

void Checkbox::setKeyboardPos(bool whereIn) {
	this->KeyBoardPos = whereIn;
}

bool Checkbox::getKeyboardPos() {
	return this->KeyBoardPos;
}

Checkbox::Checkbox() {}