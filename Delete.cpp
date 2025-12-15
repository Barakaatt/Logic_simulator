#include "Delete.h"
#include "ApplicationManager.h" 
#include "GUI\Output.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{
}

Delete::~Delete()
{
}

void Delete::ReadActionParameters()
{
}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();

	
	pOut->PrintMsg("Delete Action: Deleting selected components...");

	
	pManager->DeleteSelectedComponents();


	pOut->ClearStatusBar();
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}