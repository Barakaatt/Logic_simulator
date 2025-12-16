#pragma once
#ifndef _SWITCH_H
#define _SWITCH_H

#include "Components/Gate.h"

class SWITCH : public Gate
{
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);
	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);
	virtual void setInputPinStatus(int n, STATUS s);

	void set_state(STATUS s);
};

#endif