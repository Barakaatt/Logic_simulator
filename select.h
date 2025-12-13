#pragma once
#pragma once
#include "Action.h"
#include "Components/Component.h"

class Select : public Action
{
private:
    int Cx, Cy;          // clicked coordinates
    Component* pComp;    // component under click (if any)

public:
    Select(ApplicationManager* pApp);
    virtual ~Select();

    virtual void ReadActionParameters();   // get click point
    virtual void Execute();                // perform select / toggle
    virtual void Undo() {}                // not used
    virtual void Redo() {}                // not used
};
