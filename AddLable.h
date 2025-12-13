#pragma once
#pragma once

#include "Action.h"
#include <string>
#include "../Components/Component.h"

class AddLabel : public Action
{
private:
    int m_x, m_y;           
    std::string m_Label;    
    Component* m_pComp;    

public:
    AddLabel(ApplicationManager* pApp);
    virtual ~AddLabel();

    virtual void ReadActionParameters(); // ???? ???? ????? ?????
    virtual void Execute();              // ???? ????? ??? label ??? ??? component
};

