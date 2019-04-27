#include "textbox.h"
#include <iostream>
#include <stdlib.h>

TextBox::TextBox(short width, short top, short left, std::string value) : 
    width(width), top(top), left(left), value(value), hasBorder(true),
    color(FOREGROUND_RED | FOREGROUND_INTENSITY){
        curserPos = {left + 1 + value.length(), top + 1};
        oldWidth = width;
    }

void TextBox:: handleKeyboardEvent(KEY_EVENT_RECORD& event){
    int txtLength = value.length();
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if(!event.bKeyDown) return;
    
    if((event.wVirtualKeyCode >= 0x30 && event.wVirtualKeyCode <= 0x5a) || event.wVirtualKeyCode == 0x20) {
        unsigned long diff = curserPos.X - this->left;
        curserPos = { curserPos.X + 1, curserPos.Y };
        value.insert(diff - 1, &event.uChar.AsciiChar);
        if(value.length() >= width) width += 1;
        draw();
    }

    if(event.wVirtualKeyCode == VK_LEFT || event.wVirtualKeyCode == VK_RIGHT){
        auto offset = curserPos.X - left;
        if(offset - 1 > 0 && event.wVirtualKeyCode == VK_LEFT){
            curserPos = { curserPos.X - 1, curserPos.Y };
            SetConsoleCursorPosition(handle, curserPos);
        }

        if(offset - 1 < txtLength && event.wVirtualKeyCode == VK_RIGHT){
            curserPos = { curserPos.X + 1, curserPos.Y };
            SetConsoleCursorPosition(handle, curserPos);
        }
    }

    if(txtLength > 0 && event.wVirtualKeyCode == VK_BACK){
        unsigned long diff = curserPos.X - left;
        if(event.wVirtualKeyCode == VK_DELETE && diff - 1 < value.length()){
            value.erase(value.begin() + diff - 1);
        }
        if(event.wVirtualKeyCode == VK_BACK && value.length() > 0){
            if(diff - 1 > 0){
                value.erase(value.begin() + diff - 2);
                curserPos = { curserPos.X - 1, curserPos.Y };
            }
        }
        if(value.length() < width){
            oldWidth = width;
            width - 2 > 10 ? width -= 1 : 10;
        }
        
        draw();
    }
}

void TextBox::draw(){
    COORD coord =  {left, top};
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
    SetConsoleTextAttribute(handle, color | (background << 4));

    std::cout << (char)0xda;
    for(int i = 0; i < width; ++i)
        std::cout << (char)0xc4;    
    std::cout << (char)0xbf;

    for(int i = width; i < oldWidth; ++i) std::cout << " ";

    SetConsoleCursorPosition(handle,{ coord.X, coord.Y + 1 });
    std::cout << (char)0xb3;

    for(int i = 0; i < value.length(); ++i) std::cout << value[i];
    for(int i = value.length(); i < width; ++i) std::cout << " ";
    for(int i = width; i < oldWidth + 1; ++i) std::cout << " ";

    SetConsoleCursorPosition(handle,{ left + width + 1, top + 1 });
    std::cout << (char)0xb3;

    SetConsoleCursorPosition(handle,{ left, top + 2 });
    std::cout << (char)0xc0;
    for(int i = 0; i < width; ++i)
        std::cout << (char)0xc4;  
    std::cout << (char)0xd9;
        
    for(int i = width; i < oldWidth; ++i) std::cout << " ";

    SetConsoleCursorPosition(handle, curserPos);
}