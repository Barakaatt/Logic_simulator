#include "Select.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* pApp) : Action(pApp)
{
    Cx = Cy = 0;
    pComp = nullptr;
}

Select::~Select()
{
}

void Select::ReadActionParameters()
{
    // get input & output pointers from the manager
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    // ask user to click
    pOut->PrintMsg("Select: click on a component to select/deselect it");
    pIn->GetPointClicked(Cx, Cy);   // fills Cx, Cy
    pOut->ClearStatusBar();
}

void Select::Execute()
{
  
    ReadActionParameters();

    pComp = pManager->GetComponentAt(Cx, Cy);

    Output* pOut = pManager->GetOutput();

    if (pComp)
    {
   
        bool currently = pComp->isselected();
        pComp->setselected(!currently);

        if (!currently)
            pOut->PrintMsg("Component selected");
        else
            pOut->PrintMsg("Component deselected");
    }
    else
    {
        // nothing clicked
        pOut->PrintMsg("No component at clicked point");
    }

    // refresh view so selection visuals update
    pManager->UpdateInterface();
}
