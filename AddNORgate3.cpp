#include "AddNORgate3.h"
#include "ApplicationManager.h"
#include "..\\GUI\\Input.h"
#include "..\\GUI\\Output.h"
#include "..\\GUI\\UI_Info.h"
#include "..\\Components\\NOR3.h"

AddNORgate3::AddNORgate3(ApplicationManager* pApp) : Action(pApp)
{
}

AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");
    pIn->GetPointClicked(Cx, Cy);
    pOut->ClearStatusBar();
}

void AddNORgate3::Execute()
{
 
    ReadActionParameters();
    int Len = UI.NOR3_Width;   
    int Wdth = UI.NOR3_Height;

    GraphicsInfo GInfo;
    GInfo.x1 = Cx - Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y2 = Cy + Wdth / 2;
#ifdef NOR3_FANOUT
    NOR3* pA = new NOR3(GInfo, NOR3_FANOUT);
#else
    NOR3* pA = new NOR3(GInfo, 3);
#endif

    pManager->AddComponent(pA);
}

void AddNORgate3::Undo()
{
    // optional
}

void AddNORgate3::Redo()
{
    // optional
}
