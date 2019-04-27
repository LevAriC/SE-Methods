// Lev Ari Cohen | Guy Chriqui | Michael Makmel | Dor Munsa //
//   304829807   |  203137641  |   203447834    | 204325229 //

#include "textbox.h"

int main(int argc, char const* argv[]){
    auto handle = GetStdHandle(STD_INPUT_HANDLE);
    TextBox tb(22, 3, 3, "<-- Text Goes Here -->");
    tb.draw();

    while(1){
        INPUT_RECORD ir;
        DWORD count;
        ReadConsoleInput(handle, &ir, 1, &count);

        if(count){
            if(ir.EventType == KEY_EVENT){
                tb.handleKeyboardEvent(ir.Event.KeyEvent);
            }
        }
    }

    return 0;
}