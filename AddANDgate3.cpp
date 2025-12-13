#include "AddANDgate3.h"
#include "ApplicationManager.h"
#include "..\\GUI\\Input.h"
#include "..\\GUI\\Output.h"
#include "..\\GUI\\UI_Info.h"
#include "..\\Components\\AND3.h"

AddANDgate3::AddANDgate3(ApplicationManager* pApp) : Action(pApp)
{
}

AddANDgate3::~AddANDgate3(void)
{
}

void AddANDgate3::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("3-Input AND Gate: Click to add the gate");
    pIn->GetPointClicked(Cx, Cy);
    pOut->ClearStatusBar();
}

void AddANDgate3::Execute()
{
    ReadActionParameters();

    int Len = UI.AND3_Width;   
    int Wdth = UI.AND3_Height;

    GraphicsInfo GInfo;
    GInfo.x1 = Cx - Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y2 = Cy + Wdth / 2;

#ifdef AND3_FANOUT
    AND3* pA = new AND3(GInfo, AND3_FANOUT);
#else
    AND3* pA = new AND3(GInfo, 3);  
#endif

    pManager->AddComponent(pA);
}

void AddANDgate3::Undo()
{
    // optional
}

void AddANDgate3::Redo()
{
    // optional
}
