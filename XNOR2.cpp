#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR2::Operate()
{
	// Calculate the output status as the XNOR of the two input pins
	STATUS in1 = m_InputPins[0].getStatus();
	STATUS in2 = m_InputPins[1].getStatus();

	// XNOR: output is HIGH if both inputs are the same, LOW otherwise
	if (in1 == in2)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Component* XNOR2::Clone() const
{
    return new XNOR2(m_GfxInfo, XNOR2_FANOUT);
}

string XNOR2::GetType() const
{
	return "XNOR2";
}

bool XNOR2::IsInside(int x, int y) const
{
	return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 &&
		y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);
	
}
void NOR2::Reset()
{
	m_OutputPin.setStatus(LOW);
	for (int i = 0; i < m_Inputs; ++i)
	{
		m_InputPins[i].setStatus(LOW);
	}
}
