#include "EditLabel.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"   
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

EditLabel::EditLabel(ApplicationManager* pApp) : Action(pApp)
{
    ClickedX = ClickedY = 0;
    m_NewLabel = "";
}

EditLabel::~EditLabel() {}

void EditLabel::ReadActionParameters()
{
    // get pointers to input/output
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Edit Label: click on a component to edit its label...");
    pIn->GetPointClicked(ClickedX, ClickedY);    // wait user click
    pOut->ClearStatusBar();

    // ask for new label text
    pOut->PrintMsg("Enter new label text:");
    m_NewLabel = pIn->GetSrting(pOut);   // requires GetString implemented in Input
    pOut->ClearStatusBar();
}

void EditLabel::Execute()
{
    // read parameters (click + new label)
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();

    // get component at clicked position
    Component* pComp = pManager->GetComponentAt(ClickedX, ClickedY);
    if (!pComp)
    {
        pOut->PrintMsg("No component selected. Edit cancelled.");
        return;
    }

    // set new label on component (needs SetLabel implemented in Component)
    pComp->SetLabel(m_NewLabel);

    // refresh UI
    pManager->UpdateInterface();

    pOut->PrintMsg("Label updated.");
}
