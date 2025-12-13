#ifndef _ADD_AND_GATE_H
#define _ADD_AND_GATE_H

#include "action.h"
#include "..\Components\AND2.h"

class AddANDgate2 :	public Action
{
private:
	
	int Cx, Cy;	
	int x1, y1, x2, y2;	
public:
	AddANDgate2(ApplicationManager *pApp);
	virtual ~AddANDgate2(void);
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif