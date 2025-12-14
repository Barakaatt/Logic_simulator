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