#include "MessageBox.h"

bool MsgBox::canGetFocus() { return TRUE; }

MsgBox::MsgBox(short left, short top, string message) :
	Control(left, top), label(left, top, message), panel(new SingleBorder(), left, top, message.size() + 4, 4), isVisible(FALSE) {}

void MsgBox::draw(Graphics& graphics, int x, int y, size_t size)
{
	panel.pushToControlsList(&label);

	if (isVisible)
		panel.draw(graphics, x, y, size);
}

void MsgBox::buttonEvent() 
{
	if (isVisible)
		isVisible = false;
	else
		isVisible = true;
}
