#ifndef _NAND2_H
#define _NAND2_H

/*
  Class NAND2
  -----------
  represent the 2-input NAND gate
*/

#include "Components/Gate.h"

class NAND2 :public Gate
{
public:
	NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate() override;	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut) override;	//Draws 2-input gate

	virtual int GetOutPinStatus() override;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) override;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s) override;	//set status of Inputpin # n, to be used by connection class.

	// Add this to fix the abstract class error
	virtual Component* Clone() const override;
	virtual string GetType() const override;
	virtual bool IsInside(int x, int y) const override; // <-- Add this pure virtual function implementation
};

#endif