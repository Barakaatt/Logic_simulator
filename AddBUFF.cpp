#include "AddBUFF.h"
#include"ApplicationManager.h"
#include "GUI\\Input.h"
#include "GUI\\Output.h"
#include "GUI\\UI_Info.h"
#include "BUFF.h"

AddBUFF::AddBUFF(ApplicationManager* pApp) : Action(pApp)
{
}

AddBUFF::~AddBUFF(void)
{
}

void AddBUFF::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("BUFFER Gate: Click to add the gate");
    pIn->GetPointClicked(Cx, Cy);
    pOut->ClearStatusBar();
}

void AddBUFF::Execute()
{
    ReadActionParameters();
    int Len = UI.BUFFER2_Width;  
    int Wdth = UI.BUFFER2_Height;

    GraphicsInfo GInfo;
    GInfo.x1 = Cx - Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y2 = Cy + Wdth / 2;
#ifdef BUFF_FANOUT
    BUFF* pA = new BUFF(GInfo, BUFF_FANOUT);
#else
    BUFF* pA = new BUFF(GInfo, 1);
#endif

    pManager->AddComponent(pA);
}

void AddBUFF::Undo()
{
    
}

void AddBUFF::Redo()
{
    // optional: implement per-project Redo system
}
