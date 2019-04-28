// Lev Ari Cohen | Guy Chriqui | Michael Makmel | Dor Munsa //
//   304829807   |  203137641  |   203447834    | 204325229 //

#include "checkList.h"

#define OPTIONS_NUMBER 15

using namespace std;

void ShowConsoleCursor(bool showFlag){

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main(int argc, char** argv) {

	vector<string> options;
	string current_Option = "Option" ;
	ShowConsoleCursor(false);

	DWORD prev_mode;
    HANDLE  hInput = GetStdHandle(STD_INPUT_HANDLE ) ;
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS |  ENABLE_MOUSE_INPUT | ENABLE_WINDOW_INPUT | ENABLE_INSERT_MODE) ;


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
	cout << "   ########### Options List ###########\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);

	for(int i = 0 ; i < OPTIONS_NUMBER ; i ++ )
		options.push_back(current_Option + " " + to_string(i+1));

	Checklist checkList(options, 15, 3);
	checkList.drawList();
	HANDLE handler = GetStdHandle(STD_INPUT_HANDLE);

	while (true) {
		INPUT_RECORD input;
		DWORD countDword;
		ReadConsoleInput(handler, &input, 1, &countDword);
		checkList.inputHandler(input);

	}
}

