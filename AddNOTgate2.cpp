#include "AddNOTgate2.h"
#include "..\\ApplicationManager.h"
#include "..\\GUI\\Input.h"
#include "..\\GUI\\Output.h"
#include "..\\GUI\\UI_Info.h"

AddNOTgate2::AddNOTgate2(ApplicationManager* pApp) : Action(pApp)
{
}

AddNOTgate2::~AddNOTgate2(void)
{
}

void AddNOTgate2::ReadActionParameters()
{
    //Get pointers
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    //Print Message
    pOut->PrintMsg("NOT Gate: Click to add the gate");

    //Wait for user click
    pIn->GetPointClicked(Cx, Cy);

    //Clear status bar
    pOut->ClearStatusBar();
}

void AddNOTgate2::Execute()
{
    ReadActionParameters();
    int Len = UI.NOT2_Width;
    int Wdth = UI.NOT2_Height;

    x1 = Cx - Len / 2;
    y1 = Cy - Wdth / 2;
    x2 = Cx + Len / 2;
    y2 = Cy + Wdth / 2;

    GraphicsInfo GInfo;
    GInfo.x1 = x1;
    GInfo.y1 = y1;
    GInfo.x2 = x2;
    GInfo.y2 = y2;

    
    NOT* pA = new NOT(GInfo, NOT_FANOUT);

   
    pManager->AddComponent(pA);
}

void AddNOTgate2::Undo()
{
    //optional
}

void AddNOTgate2::Redo()
{
    //optional
}
