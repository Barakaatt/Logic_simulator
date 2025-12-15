#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = DEEPPINK;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
void Output::DrawLabel(string label, int x, int y) const
{
	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLACK);
	pWind->DrawString(x, y, label);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{

	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight); //Clear previous toolbar

	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "Images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2] = "Images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_XOR2] = "Images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_NAND2] = "Images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOT2] = "Images\\Menu\\Menu_NOT2.jpg";
	MenuItemImages[ITM_NOR2] = "Images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "Images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_BUFFER2] = "Images\\Menu\\Menu_BUFFER2.jpg";
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_SWITCH] = "Images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_LED] = "Images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_AND3] = "Images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "Images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "Images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_SIM_MODE] = "Images\\Menu\\Menu_SIM.jpg";

	// ADD IMAGE FOR THESE
	MenuItemImages[ITM_CONNECTION] = "Images\\Menu\\Menu_CONNECTION.jpg";




	MenuItemImages[ITM_COPY] = "Images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ITM_CUT] = "Images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ITM_PASTE] = "Images\\Menu\\Menu_PASTE.jpg";
	MenuItemImages[ITM_DELETE] = "Images\\Menu\\Menu_DELETE.jpg";
	MenuItemImages[ITM_MOVE] = "Images\\Menu\\Menu_MOVE.jpg";
	MenuItemImages[ITM_NEWFILE] = "Images\\Menu\\Menu_NEWFILE.jpg";
	MenuItemImages[ITM_SAVE] = "Images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_LOAD] = "Images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages[ITM_UNDO] = "Images\\Menu\\Menu_UNDO.jpg";
	MenuItemImages[ITM_REDO] = "Images\\Menu\\Menu_REDO.jpg";
	MenuItemImages[ITM_LABEL] = "Images\\Menu\\Menu_LABEL.jpg";
	MenuItemImages[ITM_EDIT_LABEL] = "Images\\Menu\\Menu_EDIT_LABEL.jpg";





	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);//Clear previous toolbar
	UI.AppMode = SIMULATION;
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "Images\\Menu\\Menu_SIM.jpg";
	MenuItemImages[ITM_TRUTH] = "Images\\Menu\\Menu_TRUTH.jpg";
	MenuItemImages[ITM_EXIT2] = "Images\\Menu\\Menu_Exit.jpg";
	// ADD IMAGE FOR THESE
	MenuItemImages[ITM_PROBE] = "Images\\Menu\\Menu_PROBE.jpg";
	MenuItemImages[ITM_VALIDATE] = "Images\\Menu\\Menu_VALIDATE.jpg";
	MenuItemImages[ITM_DSN_MODE] = "Images\\Menu\\Menu_DSN_MODE.jpg";



	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//Simulation Mode

//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)




//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected)
{
	string GateImage;

	if (selected)
		GateImage = "Images\\Gates\\Gate_OR2_HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected)
{
	std::string GateImage;

	if (selected) // highlighted image when selected
		GateImage = "Images\\Gates\\Gate_NAND2_HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected)
{
	std::string GateImage;

	if (selected) // highlighted image when selected
		GateImage = "Images\\Gates\\Gate_XOR2_HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawBUFFER2(GraphicsInfo r_GfxInfo, bool selected)
{
	std::string GateImage;

	if (selected) // highlighted image when selected
		GateImage = "Images\\Gates\\Gate_BUFFER2_HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_BUFFER2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.BUFFER2_Width, UI.BUFFER2_Height);
}
void Output::DrawNOT2(GraphicsInfo r_GfxInfo, bool selected)
{
	std::string GateImage;

	if (selected) // highlighted image when selected
		GateImage = "Images\\Gates\\Gate_NOT2_HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOT2.jpg";

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT2_Width, UI.NOT2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected)
{
	std::string GateImage;

	if (selected) // highlighted image when selected
		GateImage = "Images\\Gates\\Gate_NOR2_HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected)
{
	std::string GateImage;

	if (selected) // highlighted image when selected
		GateImage = "Images\\Gates\\Gate_XNOR2_HI.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";


	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}


void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool on, bool selected) const
{
	string img;
	if (selected)
	{
		if (on)
			img = "Images\\Gates\\Gate_SWITCH_HI.jpg";
		else
			img = "Images\\Gates\\Gate_SWITCH_HI.jpg"; // add ON AND OFF SWITCH
	}
	else
	{
		if (on)
			img = "Images\\Gates\\Gate_SWITCH.jpg";
		else
			img = "Images\\Gates\\Gate_SWITCH.jpg";
	}
	pWind->DrawImage(img, r_GfxInfo.x1, r_GfxInfo.y1, UI.SWITCH_Width, UI.SWITCH_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string img;
	if (selected)
		img = "Images\\Gates\\Gate_AND3.jpg";// add highlighted image when available
	else
		img = "Images\\Gates\\Gate_AND3.jpg";

	pWind->DrawImage(img, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string img;
	if (selected)
		img = "Images\\Gates\\Gate_NOR3.jpg";// add highlighted image when available
	else
		img = "Images\\Gates\\Gate_NOR3.jpg";

	pWind->DrawImage(img, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string img;
	if (selected)
		img = "Images\\Gates\\Gate_XOR3.jpg"; // add highlighted image when available
	else
		img = "Images\\Gates\\Gate_XOR3.jpg";

	pWind->DrawImage(img, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool on, bool selected) const
{
	string img;
	if (selected)
	{
		if (on)
			img = "Images\\Gates\\Gate_LED_ON.jpg"; // add highlighted image when available
		else
			img = "Images\\Gates\\Gate_LED_OFF.jpg"; // add highlighted image when available
	}
	else
	{
		if (on)
			img = "Images\\Gates\\Gate_LED_ON.jpg";
		else
			img = "Images\\Gates\\Gate_LED_OFF.jpg";
	}
	pWind->DrawImage(img, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}






//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{

	color lineColor = (selected) ? UI.SelectColor : UI.ConnColor;

	int penWidth = 2;
	pWind->SetPen(lineColor, penWidth);
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1);
	pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y1, (r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2);
	pWind->DrawLine((r_GfxInfo.x2 + r_GfxInfo.x1) / 2, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);

	pWind->SetPen(BLACK, 1);
	pWind->SetBrush(lineColor);
	int r = 3;
	pWind->DrawEllipse(r_GfxInfo.x2 - r, r_GfxInfo.y2 - r, r_GfxInfo.x2 + r, r_GfxInfo.y2 + r);
}

//TODO: Add code to draw connection



Output::~Output()
{
	delete pWind;
}
