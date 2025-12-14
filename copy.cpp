#include "copy.h"
#include "ApplicationManager.h"
#include "Components/Component.h"
#include "GUI\\Input.h"
#include "GUI\\Output.h"
#include "Defs.h"

Copy::Copy(ApplicationManager* pApp) : Action(pApp)
{
    m_copied = nullptr;
}

Copy::~Copy()
{
    
}

void Copy::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Copy: Click on a component to copy it.");

    Point clickedPos;

    while (true)
    {
        pIn->GetPointClicked(clickedPos.x, clickedPos.y);
        if (clickedPos.y > UI.ToolBarHeight)
            break;
    }

    pOut->ClearStatusBar();

    m_copied = pManager->GetComponentAt(clickedPos.x, clickedPos.y);
}


void Copy::Execute()
{
    ReadActionParameters();
    Output* pOut = pManager->GetOutput();

    if (m_copied == nullptr)
    {
        pOut->PrintMsg("Copy: No component selected.");
        return;
    }

    Component* cloned = m_copied->Clone();
    if (!cloned)
    {
        pOut->PrintMsg("Copy: Failed to clone component.");
        return;
    }

    pManager->SetClipboard(cloned);

    pOut->PrintMsg("Component copied to clipboard.");
}
