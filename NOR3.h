#ifndef _NOR3_H
#define _NOR3_H

/*
  Class NAND2
  -----------
  represent the 2-input NAND gate
*/

#include "Components/Gate.h"

class NOR3 : public Gate
{
public:
	NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate() override;
	virtual void Draw(Output* pOut) override;
	virtual int GetOutPinStatus() override;
	virtual int GetInputPinStatus(int n) override;
	virtual void setInputPinStatus(int n, STATUS s) override;

	// Add this to fix the abstract class error
	virtual Component* Clone() const override;
	virtual string GetType() const override;
	virtual bool IsInside(int x, int y) const override; // <-- Add this line to implement all pure virtuals
};

#endif#pragma once

// Add this method implementation to fix the abstract class error
bool NOR3::IsInside(int x, int y) const
{
	// Simple rectangle check, can be improved as needed
	return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);
}
