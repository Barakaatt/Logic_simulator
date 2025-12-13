#include "AddConnections.h"
#include "ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\Components\Connection.h"  

AddConnection::AddConnection(ApplicationManager* pApp) : Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
    
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

   
    pOut->PrintMsg("Add Connection: click source pin (start)");
    
    pIn->GetPointClicked(x1, y1);

    pOut->PrintMsg("Add Connection: click destination pin (end)");
  
    pIn->GetPointClicked(x2, y2);

   
    pOut->ClearStatusBar();
}

void AddConnection::Execute()
{
    
    ReadActionParameters();

   
    GraphicsInfo GInfo; 
    GInfo.x1 = x1;
    GInfo.y1 = y1;
    GInfo.x2 = x2;
    GInfo.y2 = y2;

  
    Connection* pConn = new Connection(GInfo);

   
    pManager->AddComponent(pConn);

   
}

void AddConnection::Undo()
{
    
}

void AddConnection::Redo()
{
    
}
