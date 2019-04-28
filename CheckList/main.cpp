#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Hide Curser.
void ShowConsoleCursor(bool showFlag){

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}


// ################################ MAIN ################################
int main(){

    DWORD prev_mode;
    HANDLE  hInput = GetStdHandle(STD_INPUT_HANDLE ) ;

    // Save prev mode to return at the end of the App.
    GetConsoleMode(hInput, &prev_mode); 
    // Disable quick edit.
    SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS) ;

    string Menu[] = {"Option 1", "Option 2", "Option 3" , "Exit"};
    bool Selected[] = {0, 0, 0, 0};
    const int  Menu_Len = sizeof(Menu)/sizeof(*Menu);
    int selected_Option = 0;

    // Hide Curser.
    ShowConsoleCursor(false);

   // Create and clean/update the console.
    while(true){

        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        cout << "______________# Menu #______________\n\n";
       
        for (int i = 0; i < Menu_Len; ++i){

            if (i == selected_Option){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                cout << "              " << Menu[i] << endl;
            }else if(Selected[i] == 1) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << "              " << Menu[i] << endl;
            }else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << "              " << Menu[i] << endl;
            }
        }

        // Color of notifications text.
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
       
       // Handeling Keyboard & Mouse input events.
        while(true){

            // Up pressed.
            if (GetAsyncKeyState(VK_UP) != 0){
                selected_Option -= 1;
                if (selected_Option == -1)
                    selected_Option = Menu_Len-1;
                break;

            // Down pressed.
            }else if (GetAsyncKeyState(VK_DOWN) != 0) {
                selected_Option += 1;
                if (selected_Option == Menu_Len)
                    selected_Option = 0;
                break;

            // Enter/Space pressed.
            }else if (GetAsyncKeyState(VK_RETURN) != 0 || GetAsyncKeyState(VK_SPACE) != 0){
                switch (selected_Option) {
                    case 0:{
                        Selected[selected_Option] = !Selected[selected_Option];
                    } break;

                    case 1:{
                        Selected[selected_Option] = !Selected[selected_Option];
                    } break;

                    case 2:{
                        Selected[selected_Option] = !Selected[selected_Option];
                    } break;

                    case (Menu_Len-1):{
                        cout << "\n\nExiting App";
                        Sleep(1500);
                        // Enable quick edit back.
                        SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS) ;
                        return 0;
                    } break;
                }
                break;

            // Mouse pressed
            }else if(GetAsyncKeyState(VK_LBUTTON) < 0){

                //TODO: (1) get the rectangle of client window (console app window rect).
                //      (2) get the text that in the same current position of the mouse.
                //      (4) connect the text (selected option) to the option func (here its just to make text notification). WHAT GUY CHRIQUI??
                

                // Get the mouse cursor x,y position

//              POINT mousePos;
//              GetCursorPos(&mousePos);		
                HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
                INPUT_RECORD ir;
             	DWORD count;
                ReadConsoleInput(hStdin, &ir, 1, &count);
                MOUSE_EVENT_RECORD& event = ir.Event.MouseEvent;
                if(ir.EventType == MOUSE_EVENT){
                    COORD pos = event.dwMousePosition;
                    cout << "\nX: " << pos.X << "\nY: " << pos.Y;
                }

                // Just to see how it works.
//              cout << "\n\nMouse click detected : Position: " << mousePos.x << "," << mousePos.y << endl;
                Sleep(500);

                break;
            }
        }
        Sleep(100);
    }
   
    return 0;
}