#pragma once
#pragma once
#include "Action.h"

class Simulate : public Action
{
public:
    Simulate(ApplicationManager* pApp);
    virtual void Execute();
};

