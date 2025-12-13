#pragma once
#ifndef _MOVE_ACTION_H
#define _MOVE_ACTION_H

#include "Action.h"

class Move : public Action
{
private:
    int SrcX, SrcY;    
    int DstX, DstY;    
    Component* pComp;  

public:
    Move(ApplicationManager* pApp);
    virtual ~Move();

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};

#endif

