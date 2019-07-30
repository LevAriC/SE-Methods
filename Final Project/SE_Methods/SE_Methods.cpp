#include "EventEngine.h"
#include "Panel.h"
#include "CheckList.h"
#include "NumericBox.h"
#include "TextBox.h"
#include "RadioBox.h"
#include "MessageBox.h"
#include "ComboBox.h"

int main(int argc, char** argv)
{
	EventEngine eventEngine;
	Panel panel(new SingleBorder(), 1, 1, 80, 26);
	//Panel panel(new SingleBorder(), 1, 1, Color::Grey, Color::Black, 80, 30); // Doesn't Work Properly
	CheckList checkList(new DoubleBorder(), 2, 2, {"This", "Is", "A", "Check", "List"}, Color::Red, Color::White);
	RadioBox radioBox(new DoubleBorder(), 28, 2, {"Just", "A", "Radio", "Box"}, Color::Blue, Color::Yellow);
	ComboBox comboBox(new SingleBorder(), 56, 8, {"1st" , "2nd"  , "3rd" ,  "4th"}, Color::Cyan, Color::Black);
	NumericBox numericBox(new DoubleBorder(), 56, 2, -5, 5);
	//NumericBox numericBox(new DoubleBorder(), 56, 17, -5, 5, Color::Yellow, Color::Red); // Doesn't Work Properly
	TextBox textBox(new SingleBorder(), 28, 18, 25, 4, Color::Orange, Color::Purple);
	Label label(54, 19, "Miki Lev Muns Chriq", Color::Purple, Color::Bright);
	MsgBox MsgBox(20, 8, "Button Pressed");
	Button cancel(new SingleBorder(), 58, 22, "Cancel", Color::White, Color::Pink);
	Button submit(new SingleBorder(), 16, 22, "Submit", Color::Green, Color::Bright);
	submit.PushToControlsList(&MsgBox);
	
	Control* controls[] = { &checkList, &radioBox ,&textBox, &numericBox, &cancel, &submit, &MsgBox, &label, &comboBox };
	for (Control* c : controls)
		panel.pushToControlsList(c);

	panel.initPanelFocus(); 
	eventEngine.run(panel);	
}