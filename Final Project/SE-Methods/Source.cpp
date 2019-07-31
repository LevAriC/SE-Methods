#include "Common/EventEngine.h" 
#include "Controls/Panel.h"
#include "Controls/TextBox.h"
#include "Controls/NumericBox.h"
#include "Controls/ComboBox.h"
#include "Controls/CheckList.h"
#include "Controls/RadioBox.h"
#include "Controls/MessageBox.h"

int main(int argc, char** argv)
{
	EventEngine eventEngine;
	Label label(new NoBorder(), 54, 19, "I'M A PRETTY Label", Color::Black, Color::Bright);
	Panel panel(new DoubleBorder(), 1, 1, Color::Cyan, Color::Bright, 77, 26);
	TextBox textBox(new DoubleBorder(), 29, 18, 25, 4, Color::Bright, Color::Purple);
	NumericBox numericBox(new SingleBorder(), 55, 2, -10, 10, Color::Orange, Color::Purple);
	CheckList checkList(new DoubleBorder(), 3, 2, {"This", "Is", "A", "Check", "List"}, Color::Red, Color::White);
	RadioBox radioBox(new DoubleBorder(), 29, 2, {"Just", "A", "Radio", "Box"}, Color::Blue, Color::Yellow);
	ComboBox comboBox(new SingleBorder(), 55, 8, {"Combo 1" , "Combo 2"  , "Combo 3" ,  "Combo 4"}, Color::Pink, Color::Black);
	MsgBox MsgBox(new DoubleBorder(), 25, 10, "This Is A MessageBox.", Color::Bright, Color::Black);
	Button button(new SingleBorder(), 30, 22, "See Message Box", Color::Green, Color::Bright);
	button.PushToControlsList(&MsgBox);

	Control* controls[] = { &checkList, &radioBox ,&textBox, &numericBox, &button, &label, &MsgBox, &comboBox };
	for (Control* c : controls)
		panel.pushToControlsList(c);

	panel.initPanelFocus(); 
	eventEngine.run(panel);	
}