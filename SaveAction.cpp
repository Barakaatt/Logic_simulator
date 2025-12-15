#include "SaveAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
    m_Filename = "";
}

SaveAction::~SaveAction()
{
}

void SaveAction::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Save Circuit: Enter filename");
    m_Filename = pIn->GetSrting(pOut);

    if (!m_Filename.empty())
    {
        m_Filename += ".txt";
    }

    pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
    ReadActionParameters();

    if (m_Filename.empty())
    {
        Output* pOut = pManager->GetOutput();
        pOut->PrintMsg("Save cancelled");
        return;
    }

    std::ofstream outFile(m_Filename.c_str());

    if (!outFile.is_open())
    {
        Output* pOut = pManager->GetOutput();
        pOut->PrintMsg("Error: Could not create file!");
        return;
    }

    pManager->Save(outFile);
    outFile.close();

    Output* pOut = pManager->GetOutput();
    pOut->PrintMsg("Saved to " + m_Filename);
}