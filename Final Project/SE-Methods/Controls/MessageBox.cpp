#include "MessageBox.h"

bool MsgBox::canGetFocus() { return TRUE; }

MsgBox::MsgBox(Border* border, short left, short top, string message)
	: text(message), Control(left, top, border), label(new NoBorder(), left+2, top, message), okButton(new SingleBorder(), left + 8, top + 3, "Ok"), cancelButton(new SingleBorder(), left + 14, top + 3, "Cancel"), isVisible(FALSE)
{
	//okButton.PushToControlsList(this);
	//cancelButton.PushToControlsList(this);
}

MsgBox::MsgBox(Border* border, short left, short top, string message, Color backgroundColor, Color foregroundColor)
	: text(message), Control(left, top, border), label(new NoBorder(), left+2, top, message, backgroundColor, foregroundColor), okButton(new SingleBorder(), left + 8, top + 3, "Ok", backgroundColor, foregroundColor), cancelButton(new SingleBorder(), left + 14, top + 3, "Cancel", backgroundColor, foregroundColor), isVisible(FALSE)
{
	//okButton.PushToControlsList(this);
	//cancelButton.PushToControlsList(this);
	this->setBackgroundColor(backgroundColor);
	this->setForegroundColor(foregroundColor);
}

void MsgBox::draw(Graphics& graphics, int x, int y, size_t size)
{
	graphics.setBackground(backgroundColor);
	graphics.setForeground(foregroundColor);

	if (isVisible)
	{
		border->createBorder(graphics, x, y, text.size() + 8, 8);
		label.draw(graphics, left + 2, top, size);
		okButton.draw(graphics, left + 8, top + 3, size);
		cancelButton.draw(graphics, left + 14, top + 3, size);
	}
}

void MsgBox::buttonEvent() 
{
	if (isVisible)
		isVisible = false;
	else
		isVisible = true;
}

void MsgBox::mousePressed(int x, int y, bool isMousePressed)
{
	//bool tmp1 = okButton.getIsTriggered();
	//bool tmp2 = cancelButton.getIsTriggered();
	//okButton.mousePressed(x, y, isMousePressed);
	//cancelButton.mousePressed(x, y, isMousePressed);
}
