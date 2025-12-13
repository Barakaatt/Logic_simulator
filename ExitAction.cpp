#include "ExitAction.h"
#include "ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
}

ExitAction::~ExitAction(void)
{
}

void ExitAction::ReadActionParameters()
{
    // No parameters required for exit
}

void ExitAction::Execute()
{
    // Ask the ApplicationManager to exit
    pManager->Exit();
}
