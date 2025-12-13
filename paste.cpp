#include "Paste.h"
#include "ApplicationManager.h"
#include "Component.h"
#include "Input.h"
#include "Output.h"
#include "Defs.h"    // for FANOUT constants and maybe GraphicsInfo definition
#include <string>
#include "Components/AND2.h"
#include "Components/OR2.h"

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

    std::string type = copied->GetType();
    Component* newComp = nullptr;

  
    if (type == "AND2")
        newComp = new AND2(newG, AND2_FANOUT);
    else if (type == "OR2")
        newComp = new OR2(newG, OR2_FANOUT);
    else if (type == "NAND2")
        newComp = new NAND2(newG, NAND2_FANOUT);
    else if (type == "NOR2")
        newComp = new NOR2(newG, NOR2_FANOUT);
    else if (type == "XOR2")
        newComp = new XOR2(newG, XOR2_FANOUT);
    else if (type == "XNOR2")
        newComp = new XNOR2(newG, XNOR2_FANOUT);
    else if (type == "AND3")
        newComp = new AND3(newG, AND3_FANOUT);
    else if (type == "XOR3")
        newComp = new XOR3(newG, XOR3_FANOUT);
    else if (type == "NOR3")
        newComp = new NOR3(newG, NOR3_FANOUT);
    else if (type == "BUFF")
        newComp = new BUFF(newG, BUFF_FANOUT);
    else if (type == "NOT")
        newComp = new NOT(newG, NOT_FANOUT);
    else if (type == "SWITCH")
        newComp = new SWITCH(newG, SWITCH_FANOUT); // maybe fanout unused
    else if (type == "LED")
        newComp = new LED(newG, 0);
    else
    {
        pOut->PrintMsg("Paste: Unsupported type for paste!");
        return;
    }

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
