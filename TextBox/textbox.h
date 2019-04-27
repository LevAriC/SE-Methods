#include <string>
#include <windows.h>

class TextBox{ 
public:
    short oldWidth;
    short width;
    short top;
    short left;
    bool hasBorder;
    WORD color;
    WORD background;
    COORD curserPos;

    std::string value;
    TextBox(short width, short top, short left, std::string value);

    void draw();
    void handleKeyboardEvent(KEY_EVENT_RECORD&);
};