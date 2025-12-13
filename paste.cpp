#include "Paste.h"
#include "ApplicationManager.h"
#include "Components/Component.h"
#include "GUI\\Input.h"
#include "GUI\\Output.h"
#include "Defs.h"    // for FANOUT constants and maybe GraphicsInfo definition
#include <string>

Paste::Paste(ApplicationManager* pApp) : Action(pApp)
{
    m_x = m_y = 0;
}

Paste::~Paste()
{
}

void Paste::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Paste: Click where you want to paste the component.");
    pOut->ClearStatusBar();
}

void Paste::Execute()
{
    Output* pOut = pManager->GetOutput();

    Component* copied = pManager->GetClipboard();
    if (!copied)
    {
        pOut->PrintMsg("Paste: Clipboard is empty.");
        return;
    }

    
    GraphicsInfo oldG = copied->GetGraphicsInfo(); 
    int w = oldG.x2 - oldG.x1;
    int h = oldG.y2 - oldG.y1;

    GraphicsInfo newG;
    newG.x1 = m_x - w / 2;
    newG.y1 = m_y - h / 2;
    newG.x2 = newG.x1 + w;
    newG.y2 = newG.y1 + h;

	Component* newComp = copied->Clone();

    if (newComp)
    {
        pManager->AddComponent(newComp);
        pOut->PrintMsg("Pasted!");
    }
    else
    {
        pOut->PrintMsg("Paste failed to create component.");
    }
}
