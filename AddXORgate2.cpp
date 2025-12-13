#include "AddXORgate2.h"
#include "ApplicationManager.h"
#include "GUI\\Input.h"
#include "GUI\\Output.h"
#include "GUI\\UI_Info.h"
#include "XOR2.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) : Action(pApp)
{
}

AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::ReadActionParameters()
{
    
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

   
    pOut->PrintMsg("2-Input XOR Gate: Click to add the gate");

   
    pIn->GetPointClicked(Cx, Cy);

    pOut->ClearStatusBar();
}

void AddXORgate2::Execute()
{
  
    ReadActionParameters();

    
    int Len = UI.XOR2_Width;   
    int Wdth = UI.XOR2_Height;

    GraphicsInfo GInfo;
    GInfo.x1 = Cx - Len / 2;
    GInfo.x2 = Cx + Len / 2;
    GInfo.y1 = Cy - Wdth / 2;
    GInfo.y2 = Cy + Wdth / 2;

    
#ifdef XOR2_FANOUT
    XOR2* pA = new XOR2(GInfo, XOR2_FANOUT);
#else
    XOR2* pA = new XOR2(GInfo, 2); 
#endif

    pManager->AddComponent(pA);
}

void AddXORgate2::Undo()
{
    
 
}

void AddXORgate2::Redo()
{
   
    
}
