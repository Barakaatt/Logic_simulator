#ifndef _LOAD_ACTION_H
#define _LOAD_ACTION_H

#include "Actions/Action.h"
#include <string>

class LoadAction : public Action
{
private:
    std::string m_Filename;

public:
    LoadAction(ApplicationManager* pApp);
    virtual ~LoadAction();

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo() {}
    virtual void Redo() {}
};

#endif
