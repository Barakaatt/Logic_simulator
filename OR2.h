#ifndef _OR2_H
#define _OR2_H

#include "Gate.h"
#include "..\\Defs.H"
#include "..\\GUI\\UI_Info.h"

class OR2 : public Gate
{
public:
    OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
    virtual void Operate();
    virtual void Draw(Output* pOut);
    virtual int GetOutPinStatus();
    virtual int GetInputPinStatus(int n);
    virtual void setInputPinStatus(int n, STATUS s);
};

#endif
