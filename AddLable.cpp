#include "AddLable.h"
#include "ApplicationManager.h"
#include "Input.h"
#include "Output.h"
#include "Component.h"

AddLabel::AddLabel(ApplicationManager* pApp) : Action(pApp), m_x(0), m_y(0), m_pComp(nullptr) {}

AddLabel::~AddLabel() {}

void AddLabel::ReadActionParameters()
{
    Input* pIn = pManager->GetInput();
    Output* pOut = pManager->GetOutput();

    
    pOut->PrintMsg("Click on component to label...");

    
    pIn->GetPointClicked(m_x, m_y);


    m_pComp = pManager->GetComponentAt(m_x, m_y);

    if (!m_pComp) {
        pOut->PrintMsg("No component selected. Action cancelled.");
        
        return;
    }

    pOut->PrintMsg("Enter label text:");
    m_Label = pIn->GetSrting(pOut);

    pOut->ClearStatusBar();
}

void AddLabel::Execute()
{
    ReadActionParameters();

    Output* pOut = pManager->GetOutput();

    if (!m_pComp) {
       
        return;
    }

  
    m_pComp->SetLabel(m_Label);

    pOut->PrintMsg("Label set.");
}
