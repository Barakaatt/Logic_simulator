#ifndef _NOT_H
#define _NOT_H

#include "Components/Gate.h"

class NOT : public Gate
{
public:
	NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate() override;
	virtual void Draw(Output* pOut) override;
	virtual int GetOutPinStatus() override;
	virtual int GetInputPinStatus(int n) override;
	virtual void setInputPinStatus(int n, STATUS s) override;
	virtual Component* Clone() const override;
	virtual string GetType() const override;
	virtual bool IsInside(int x, int y) const override; // <-- Add this line to implement all pure virtuals
};

#endif