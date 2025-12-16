#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(1, r_FanOut)
{
	m_GfxInfo = r_GfxInfo;

	// Associate the input pin with this component
	m_InputPins[0].setComponent(this);
}

void LED::Operate()
{
	// LED doesn't calculate an output, it just visually reflects the input
	// The InputPin status is updated by the Connection during simulation
}

void LED::Draw(Output* pOut)
{
	// If the input pin is HIGH, the LED is ON
	bool isON = (GetInputPinStatus(0) == HIGH);
	pOut->DrawLED(m_GfxInfo, isON, Selected);
}

int LED::GetOutPinStatus()
{
	return LOW; // LED has no output
}

int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n].getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n].setStatus(s);
}

InputPin* LED::GetInputPin(int n)
{
	return &m_InputPins[0];
}