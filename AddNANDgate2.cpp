#include "AddNANDgate2.h"
#include "ApplicationManager.h"
#include "GUI\\Input.h"
#include "GUI\\Output.h"
#include "GUI\\UI_Info.h"
#include "NAND2.h"

AddNANDgate2::AddNANDgate2(ApplicationManager* pApp) : Action(pApp)
{
}

AddNANDgate2::~AddNANDgate2(void)
{
}

void AddNANDgate2::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");
    pIn->GetPointClicked(Cx, Cy);
    pOut->ClearStatusBar();
}

void AddNANDgate2::Execute()
{
  
    ReadActionParameters();

    int Len = UI.NAND2_Width;   
    int Wdth = UI.NAND2_Height;

    GraphicsInfo GInfo; 
    GInfo.x1 = Cx - Len / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.y2 = Cy + Wdth / 2;

  
#ifdef NAND2_FANOUT
    NAND2* pA = new NAND2(GInfo, NAND2_FANOUT);
#else
    NAND2* pA = new NAND2(GInfo, 2); // fallback fanout = 2
#endif

    pManager->AddComponent(pA);
}

void AddNANDgate2::Undo()
{
    
    
}

void AddNANDgate2::Redo()
{

    
}
