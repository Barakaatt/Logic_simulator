#pragma once
#ifndef _LED_H
#define _LED_H

#include "Components/Gate.h"

class LED : public Gate
{
	// LED treats the Gate's "InputPin" as its main input.
	// It ignores the OutputPin functionality of the base Gate class.
public:
	LED(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();
	virtual void Draw(Output* pOut);
	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);
	virtual void setInputPinStatus(int n, STATUS s);

	// Helper to get the input pin for connection
	virtual InputPin* GetInputPin(int n);
};

#endif