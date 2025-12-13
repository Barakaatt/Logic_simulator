#pragma once
#ifndef COPY_ACTION_H
#define COPY_ACTION_H

#include "Actions/Action.h"


class Copy : public Action
{
private:
    Component* m_copied; 
public:
    Copy(ApplicationManager* pApp);
    virtual ~Copy();
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};

#endif // COPY_ACTION_H
