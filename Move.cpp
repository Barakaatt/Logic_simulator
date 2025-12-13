#include "Move.h"
#include "ApplicationManager.h"
#include "GUI\\Input.h"
#include "GUI\\Output.h"
#include "Components/Component.h"

Move::Move(ApplicationManager* pApp) : Action(pApp)
{
    SrcX = SrcY = DstX = DstY = 0;
    pComp = nullptr;
}

Move::~Move() {}

void Move::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Move: Click on a component to move");
    pIn->GetPointClicked(SrcX, SrcY);

    pComp = pManager->GetComponentAt(SrcX, SrcY);

    if (!pComp)
    {
        pOut->PrintMsg("No component selected. Move cancelled.");
        
        pOut->ClearStatusBar();
        return;
    }

    pOut->PrintMsg("Click destination (top-left corner or center depending design)");
    pIn->GetPointClicked(DstX, DstY);

    pOut->ClearStatusBar();
}

void Move::Execute()
{
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();

    if (!pComp)
    {
        // nothing to move
        return;
    }
    GraphicsInfo G = pComp->GetGraphicsInfo(); 
    int w = G.x2 - G.x1;
    int h = G.y2 - G.y1;
    int new_x1 = DstX - w / 2;
    int new_y1 = DstY - h / 2;
    int new_x2 = new_x1 + w;
    int new_y2 = new_y1 + h;
    GraphicsInfo newG;
    newG.x1 = new_x1; newG.y1 = new_y1; newG.x2 = new_x2; newG.y2 = new_y2;
    pComp->SetGraphicsInfo(newG);
    pComp->UpdatePinsPosition(); 
    pManager->UpdateInterface();
}
