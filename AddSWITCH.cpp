//#include "AddSwitch.h"
//#include "ApplicationManager.h"
#include "GUI\\Input.h"
#include "GUI\\Output.h"
#include "GUI\\UI_Info.h"
#include "SWITCH.h"   
//AddSwitch::AddSwitch(ApplicationManager* pApp) : Action(pApp)
//{
//}
//
//AddSwitch::~AddSwitch(void)
//{
//}
//
//void AddSwitch::ReadActionParameters()
//{
//    Output* pOut = pManager->GetOutput();
//    Input* pIn = pManager->GetInput();
//
//    pOut->PrintMsg("Switch: Click to add the switch");
//
//    pIn->GetPointClicked(Cx, Cy);
//
//    pOut->ClearStatusBar();
//}
//
//void AddSwitch::Execute()
//{
//    ReadActionParameters();
//
//    int Len = UI.SWITCH_Width;
//    int Wdth = UI.SWITCH_Height;
//
//    GraphicsInfo GInfo;
//    GInfo.x1 = Cx - Len / 2;
//    GInfo.x2 = Cx + Len / 2;
//    GInfo.y1 = Cy - Wdth / 2;
//    GInfo.y2 = Cy + Wdth / 2;
//    Switch* pA = new Switch(GInfo);
//    pManager->AddComponent(pA);
//}
//
//void AddSwitch::Undo()
//{
//    // optional
//}
//
//void AddSwitch::Redo()
//{
//    // optional
//}

#include "AddSWITCH.h"
#include "ApplicationManager.h"

AddSwitch::AddSwitch(ApplicationManager* pApp) : Action(pApp)
{
}

AddSwitch::~AddSwitch(void)
{
}

void AddSwitch::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Switch: Click to add a Switch");

	// Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	// Clear Status Bar
	pOut->ClearStatusBar();
}

void AddSwitch::Execute()
{
	ReadActionParameters();

	// Calculate the rectangle coordinates
	int Len = UI.SWITCH_Width;
	int Wdth = UI.SWITCH_Height;

	GraphicsInfo GInfo;
	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;

	// Create the Switch component
	SWITCH* pSwitch = new SWITCH(GInfo, AND2_FANOUT); // Using default fanout
	pManager->AddComponent(pSwitch);
}

void AddSwitch::Undo()
{
}

void AddSwitch::Redo()
{
}
