#ifndef _NOR2_H
#define _NOR2_H

#include "Components/Gate.h"

class NOR2 : public Gate
{
public:
	NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOR gate
	virtual void Draw(Output* pOut);	//Draws 2-input NOR gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual Component* Clone() const override;
	virtual string GetType() const override;

	// Add this pure virtual function to implement all abstract methods from base class
	virtual bool IsInside(int x, int y) const override;
};

#endif

// Add this method implementation to fix the abstract class error
bool NOR2::IsInside(int x, int y) const
{
	// Simple rectangle check for the component's bounding box
	return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);
}
