#include "NOT.h"

NOT::NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOT::Operate()
{
    // NOT gate: output is the inverse of the first input pin
    if (m_InputPins[0].getStatus() == HIGH)
        m_OutputPin.setStatus(LOW);
    else
        m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input AND gate
void NOT::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOT2(m_GfxInfo);
}

//returns status of outputpin
int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOT::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Component* NOT::Clone() const
{
    return new NOT(m_GfxInfo, 1);
}

string NOT::GetType() const
{
	return "NOT";
}

bool NOT::IsInside(int x, int y) const
{
	return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 &&
		y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);
	
}
/*void NOT::Reset()
{
	// Reset the output pin to LOW
	m_OutputPin.setStatus(LOW);
}*/