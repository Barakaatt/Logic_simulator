#ifndef _XNOR2_H
#define _XNOR2_H

#include "Components/Gate.h"

class XNOR2 : public Gate
{
public:
	XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate() override;
	virtual void Draw(Output* pOut) override;
	virtual int GetOutPinStatus() override;
	virtual int GetInputPinStatus(int n) override;
	virtual void setInputPinStatus(int n, STATUS s) override;
	virtual Component* Clone() const override;
	virtual string GetType() const override;
	virtual bool IsInside(int x, int y) const override; // <-- Add this pure virtual function implementation
};

#endif
