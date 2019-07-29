#include "Graphics.h"
#include "EventEngine.h"
#include "Label.h"
#include "Panel.h"

int main(int argc, char** argv)
{
	EventEngine eventEngine;
	Label lab(1,1,"Mikim");

	Panel panel(new SingleBorder(), 1, 1);
	panel.setWidth(60);
	panel.setHeight(30);
	panel.pushToControlsList(&lab);
	panel.initPanelFocus(); 
	
	eventEngine.run(panel);
}