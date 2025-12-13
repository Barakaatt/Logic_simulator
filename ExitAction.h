#pragma once
#ifndef _EXIT_ACTION_H
#define _EXIT_ACTION_H

#include "Action.h"

class ExitAction : public Action
{
public:
    ExitAction(ApplicationManager* pApp);
    virtual ~ExitAction(void);

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};

#endif
