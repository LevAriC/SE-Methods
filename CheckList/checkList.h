
#include "Checkbox.h"
#include <vector>

using namespace std;

class Checklist {

	private:

		COORD listPosition;
		Checkbox *list;
		int size;
		int current;
		HANDLE HandleOutPut;
		Checkbox *item = nullptr;


	public:

		Checklist(vector<string> options, int X, int Y);
        ~Checklist();

        void MouseEvent(MOUSE_EVENT_RECORD mouseEvent);
		void KeyEvent(KEY_EVENT_RECORD keyEvent);

		void inputHandler(INPUT_RECORD input);
		void drawList();
};