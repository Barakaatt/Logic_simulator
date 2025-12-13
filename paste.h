#pragma once
#ifndef PASTE_ACTION_H
#define PASTE_ACTION_H

#include "Actions/Action.h"

class Paste : public Action
{
private:
    int m_x, m_y; 
public:
    Paste(ApplicationManager* pApp);
    virtual ~Paste();

    virtual void ReadActionParameters();
    virtual void Execute();

    virtual void Undo() {}
    virtual void Redo() {}
};

#endif 
