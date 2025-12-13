#pragma once
#ifndef _ADD_NOT_GATE_2_H
#define _ADD_NOT_GATE_2_H

#include "Actions/Action.h"

 

class ApplicationManager;

class AddNOTgate2 : public Action
{
private:
    int Cx, Cy;        
    int x1, y1, x2, y2;  

public:
    AddNOTgate2(ApplicationManager* pApp);
    virtual ~AddNOTgate2(void);

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};

#endif
