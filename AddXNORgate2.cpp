#include "AddXNORgate2.h"
#include "ApplicationManager.h"
#include "..\\GUI\\Input.h"
#include "..\\GUI\\Output.h"
#include "..\\GUI\\UI_Info.h"
#include "..\\Components\\XNOR2.h"

AddXNORgate2::AddXNORgate2(ApplicationManager* pApp) : Action(pApp)
{
}

AddXNORgate2::~AddXNORgate2(void)
{
}

void AddXNORgate2::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");
    pIn->GetPointClicked(Cx, Cy);
    pOut->ClearStatusBar();
}

void AddXNORgate2::Execute()
{
    ReadActionParameters();

    int Len = UI.XNOR2_Width;   
    int Wdth = UI.XNOR2_Height;

    GraphicsInfo GInfo;
    GInfo.x1 = Cx - Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y2 = Cy + Wdth / 2;

    
#ifdef XNOR2_FANOUT
    XNOR2* pA = new XNOR2(GInfo, XNOR2_FANOUT);
#else
    XNOR2* pA = new XNOR2(GInfo, 2); 
#endif

    pManager->AddComponent(pA);
}

void AddXNORgate2::Undo()
{
   
}

void AddXNORgate2::Redo()
{
   
}
