#include "EventEngine.h"
#include "Panel.h"
#include "TextBox.h"
#include "NumericBox.h"
#include "ComboBox.h"
#include "CheckList.h"
#include "RadioBox.h"
#include "MessageBox.h"

int main(int argc, char** argv)
{
	EventEngine eventEngine;
	Label label(new NoBorder(), 5, 21, "LABEL", Color::White, Color::Blue);
	Panel panel(new DoubleBorder(), 1, 1, Color::Black, Color::Bright, 80, 26); 
	TextBox textBox(new SingleBorder(), 45, 21, 25, 4, Color::Green, Color::Purple);
	NumericBox numericBox(new DoubleBorder(), 56, 2, -10, 10, Color::Orange, Color::Red);
	CheckList checkList(new DoubleBorder(), 2, 2, {"This", "Is", "A", "Check", "List"}, Color::Red, Color::White);
	RadioBox radioBox(new DoubleBorder(), 28, 2, {"Just", "A", "Radio", "Box"}, Color::Red, Color::Yellow);
	ComboBox comboBox(new SingleBorder(), 58, 9, {"Combo 1" , "Combo 2"  , "Combo 3" ,  "Combo 4"}, Color::Purple, Color::White);
	MsgBox MsgBox(new DoubleBorder(), 25, 10, "This Is A MessageBox.", Color::Bright, Color::Black);
	Button button(new SingleBorder(), 20, 22, "See Message Box", Color::Bright, Color::Black);
	button.PushToControlsList(&MsgBox);

	Control* controls[] = { &checkList, &radioBox ,&textBox, &numericBox, &button, &label, &MsgBox, &comboBox };
	for (Control* c : controls)
		panel.pushToControlsList(c);

	panel.initPanelFocus(); 
	eventEngine.run(panel);	
}