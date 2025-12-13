#pragma once
#pragma once
#ifndef EDIT_LABEL_ACTION_H
#define EDIT_LABEL_ACTION_H

#include "Actions/Action.h"

#include <string>

class EditLabel : public Action
{
private:
    int ClickedX, ClickedY;
    std::string m_NewLabel;

public:
    EditLabel(ApplicationManager* pApp);
    virtual ~EditLabel();

    // overrides
    virtual void ReadActionParameters();  // read click + new label
    virtual void Execute();               // perform edit
    virtual void Undo() {}                // optional
    virtual void Redo() {}                // optional
};

#endif

