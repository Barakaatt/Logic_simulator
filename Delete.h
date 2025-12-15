#pragma once
#ifndef _DELETE_H
#define _DELETE_H

#include "Actions/Action.h"

class Delete : public Action
{
public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete();

	
	virtual void ReadActionParameters();

	//Execute action (code for deleting)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif