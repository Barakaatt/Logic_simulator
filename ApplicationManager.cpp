#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "AddORgate2.h"
#include "AddNOTgate2.h"
#include "AddXORgate2.h"
#include "AddNANDgate2.h"
#include "AddNORgate2.h"
#include "AddXNORgate2.h"
#include "AddBUFF.h"
#include "AddSWITCH.h"
#include "AddLED.h"
#include "AddANDgate3.h"
#include "AddXOR3gate.h"
#include "AddNORgate3.h"
#include "AddConnections.h"
#include "ExitAction.h"
#include "Move.h"
#include "copy.h"
#include "paste.h"
#include "EditLabel.h"
#include "select.h"
#include "SaveAction.h"
#include "LoadAction.h"
#include "components/Connection.h"
#include "components/Gate.h"
#include "Delete.h"
#include <fstream>


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	Clipboard = nullptr;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}

///////////////////////////////////////// Neblo  ///////////////////////////////////////////////////////

void ApplicationManager::Save(ofstream& file)
{
	// Count components (not connections)
	int gateCount = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i])
			gateCount++;
	}

	// Write count
	file << gateCount << endl;

	// Save all components
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i])
		{
			CompList[i]->Save(file);
		}
	}

	// Write connections header
	file << "Connections" << endl;

	// Write end marker
	file << "-1" << endl;
}

void ApplicationManager::Load(ifstream& file)
{
	// Clear everything
	ClearAllComponents();
	Component::ResetIDCounter();

	// Read count
	int compCount;
	file >> compCount;

	// Load each component
	for (int i = 0; i < compCount; i++)
	{
		string type;
		file >> type;

		Component* pComp = nullptr;
		GraphicsInfo gfx;

		if (type == "AND2")
		{
			pComp = new AND2(gfx, AND2_FANOUT);
			pComp->Load(file);
		}
		else if (type == "OR2")
		{
			pComp = new OR2(gfx, OR2_FANOUT);
			pComp->Load(file);
		}
		else if (type == "NOT")
		{
			pComp = new NOT(gfx, NOT2_FANOUT);
			pComp->Load(file);
		}
		else if (type == "XOR2")
		{
			pComp = new XOR2(gfx, XOR2_FANOUT);
			pComp->Load(file);
		}
		else if (type == "NAND2")
		{
			pComp = new NAND2(gfx, NAND2_FANOUT);
			pComp->Load(file);
		}
		else if (type == "NOR2")
		{
			pComp = new NOR2(gfx, NOR2_FANOUT);
			pComp->Load(file);
		}
		else if (type == "NOR3")
		{
			pComp = new NOR3(gfx, NOR3_FANOUT);
			pComp->Load(file);
		}
		else if (type == "XNOR2")
		{
			pComp = new XNOR2(gfx, XNOR2_FANOUT);
			pComp->Load(file);
		}
		else if (type == "BUFF")
		{
			pComp = new BUFF(gfx, BUFF_FANOUT);
			pComp->Load(file);
		}
		else if (type == "AND3")
		{
			pComp = new AND3(gfx, AND3_FANOUT);
			pComp->Load(file);
		}
		else if (type == "XOR3")
		{
			pComp = new XOR3(gfx, XOR3_FANOUT);
			pComp->Load(file);
		}

		if (pComp)
			AddComponent(pComp);
	}

	// Skip connections for now (you can add later)
	string line;
	while (getline(file, line))
	{
		if (line == "-1")
			break;
	}
}

Component* ApplicationManager::GetComponentByID(int id)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] && CompList[i]->GetID() == id)
			return CompList[i];
	}
	return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int ApplicationManager::GetCompCount()
{
	return CompCount;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);	
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_INV:
			pAct = new AddNOTgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_Buff:
			pAct = new AddBUFF(this);
			break;
		//case ADD_Switch:
		//	pAct = new AddSwitch(this);
		//	break;
		//case ADD_LED:
		//	pAct = new AddLED(this);
		//	break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		//case ADD_CONNECTION:
		//	pAct = new AddConnection(this);
		//	break;
		case EXIT:
			pAct = new ExitAction(this);
			break;
		case MOVE:   
			pAct = new Move(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case EDIT_Label:
			pAct = new EditLabel(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case Simulate:
			pAct = new Simulate(this);
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
void ApplicationManager::Exit()
{
	exit(0);
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}



Component* ApplicationManager::GetComponentAt(int x, int y)
{
	for (int i = CompCount - 1; i >= 0; i--)
	{
		if (CompList[i]->IsInside(x, y))
			return CompList[i];
	}
	return nullptr;
}

	void ApplicationManager::SetClipboard(Component* pComp)
	{
		if (Clipboard)
			delete Clipboard;
		Clipboard = pComp;
	}

	Component* ApplicationManager::GetClipboard()
	{
		return Clipboard;
	}

	// in ApplicationManager.h (private)


	// in ApplicationManager.cpp construct

	// methods (in header)

	// in destructor: if (mClipboard) delete mClipboard;


////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}


//////////////////////////////////////////////////////////////////////// Ahmed's additions ////////////////////////////////////////////////
Component* ApplicationManager::GetClickedComponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->Inside(x, y))
			return CompList[i];
	}
	return NULL;
}
//////////////////////////////////////////////////////////////////////// Ahmed's additions ////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////// Tamim's additions ////////////////////////////////////////////////
void ApplicationManager::DeleteSelectedComponents()
{
	for (int i = CompCount - 1; i >= 0; i--)
	{
		if (CompList[i]->isselected())
		{
			DeleteComponent(i);
		}
	}
	// Update the screen immediately after deletion
	if (OutputInterface)
		OutputInterface->ClearDrawingArea();
}

void ApplicationManager::DeleteComponent(int index)
{
	if (index < 0 || index >= CompCount) return;

	Component* pComp = CompList[index];

	
	Connection* pConn = dynamic_cast<Connection*>(pComp);
	if (pConn)
	{
		OutputPin* pSrcPin = pConn->getSourcePin();
		if (pSrcPin)
		{
			pSrcPin->RemoveConnection(pConn);
		}
	}


	Gate* pGate = dynamic_cast<Gate*>(pComp);
	if (pGate)
	{
		
		int numInputs = pGate->GetNoOfInputs(); 
		for (int k = 0; k < numInputs; k++)
		{
			InputPin* pInPin = pGate->GetInputPin(k);

			
			for (int j = CompCount - 1; j >= 0; j--)
			{
				Connection* pTargetConn = dynamic_cast<Connection*>(CompList[j]);
				if (pTargetConn && pTargetConn->getDestPin() == pInPin)
				{
					DeleteComponent(j);
				}
			}
		}

		
		OutputPin* pOutPin = pGate->GetOutputPin();
		
		for (int j = CompCount - 1; j >= 0; j--)
		{
			Connection* pTargetConn = dynamic_cast<Connection*>(CompList[j]);
			if (pTargetConn && pTargetConn->getSourcePin() == pOutPin)
			{
				DeleteComponent(j); 
			}
		}
	}

	// --- Actual Deletion from List ---
	delete CompList[index];
	CompList[index] = NULL;

	// Shift the remaining components to fill the gap
	for (int i = index; i < CompCount - 1; i++)
	{
		CompList[i] = CompList[i + 1];
	}
	CompList[CompCount - 1] = NULL;
	CompCount--;

	if (pConn)
	{
		OutputPin* pSrcPin = pConn->getSourcePin();
		if (pSrcPin) pSrcPin->RemoveConnection(pConn);

		//Resets to low
		InputPin* pDstPin = pConn->getDestPin();
		if (pDstPin) pDstPin->setStatus(LOW);
	}
}
//////////////////////////////////////////////////////////////////////// Tamim's additions ////////////////////////////////////////////////
void ApplicationManager::Simulate()
{
	// 1) Reset outputs
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Reset();
	}

	// 2) Operate all components
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Operate();
	}

	UpdateInterface();  
}
