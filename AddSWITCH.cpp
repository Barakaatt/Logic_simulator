//#include "AddSwitch.h"
//#include "ApplicationManager.h"
//#include "GUI\\Input.h"
//#include "GUI\\Output.h"
//#include "GUI\\UI_Info.h"
//#include "Components/SWITCH.h"   
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
