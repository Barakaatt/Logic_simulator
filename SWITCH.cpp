#include "SWITCH.h"
#include "Defs.h"
#include "ApplicationManager.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(0, r_FanOut)
{
	m_GfxInfo = r_GfxInfo;
	
	m_OutputPin.setStatus(LOW);
}

void SWITCH::Operate()
{

}

void SWITCH::Draw(Output* pOut)
{
	// Draw the switch based on its current state (High = ON, Low = OFF)
	bool isON = (m_OutputPin.getStatus() == HIGH);
	pOut->DrawSwitch(m_GfxInfo, isON, isselected());
}

int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int SWITCH::GetInputPinStatus(int n)
{
	return LOW; // Switch has no inputs
}

void SWITCH::setInputPinStatus(int n, STATUS s)
{
	// Switch has no inputs to set
}

void SWITCH::set_state(STATUS s)
{
	m_OutputPin.setStatus(s);
}