#include "AddNORgate2.h"
#include "ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h"


AddNORgate2::AddNORgate2(ApplicationManager* pApp) : Action(pApp)
{
}

AddNORgate2::~AddNORgate2(void)
{
}

void AddNORgate2::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("2-Input NOR Gate: Click to add the gate");
    pIn->GetPointClicked(Cx, Cy);
    pOut->ClearStatusBar();
}

void AddNORgate2::Execute()
{
   
    ReadActionParameters();

 
    int Len = UI.NOR2_Width;  
    int Wdth = UI.NOR2_Height;

    GraphicsInfo GInfo;
    GInfo.x1 = Cx - Len / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.y2 = Cy + Wdth / 2;

#ifdef NOR2_FANOUT
    NOR2* pA = new NOR2(GInfo, NOR2_FANOUT);
#else
    NOR2* pA = new NOR2(GInfo, 2); 
#endif

    pManager->AddComponent(pA);
}

void AddNORgate2::Undo()
{
  
 
}

void AddNORgate2::Redo()
{
   
}
