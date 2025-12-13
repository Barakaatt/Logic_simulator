#pragma once
#ifndef _ADD_BUFF_GATE_H
#define _ADD_BUFF_GATE_H

#include "Actions/Action.h"




class ApplicationManager;

class AddBUFF : public Action
{
private:
    int Cx, Cy;        
    int x1, y1, x2, y2; 

public:
    AddBUFF(ApplicationManager* pApp);
    virtual ~AddBUFF(void);

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};

#endif

