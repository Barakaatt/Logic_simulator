#include "LoadAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
    m_Filename = "";
}

LoadAction::~LoadAction()
{
}

void LoadAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Load Circuit: Enter filename");
    m_Filename = pIn->GetSrting(pOut);
    
    if (!m_Filename.empty())
    {
        m_Filename += ".txt";
    }
    
    pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
    ReadActionParameters();
    
    if (m_Filename.empty())
    {
        Output* pOut = pManager->GetOutput();
        pOut->PrintMsg("Load cancelled");
        return;
    }

    std::ifstream inFile(m_Filename.c_str());
    
    if (!inFile.is_open())
    {
        Output* pOut = pManager->GetOutput();
        pOut->PrintMsg("Error: File not found!");
        return;
    }

    pManager->Load(inFile);
    inFile.close();

    Output* pOut = pManager->GetOutput();
    pOut->PrintMsg("Loaded from " + m_Filename);
    pManager->UpdateInterface();
}
