#include "OR2.h"

OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR2::Operate()
{
	// Calculate the output status as the ORing of the two input pins
	// If any input is HIGH, output is HIGH; otherwise, output is LOW
	if (m_InputPins[0].getStatus() == HIGH || m_InputPins[1].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input AND gate
void OR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo);
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Component* OR2::Clone() const
{
    // Use the current object's m_GfxInfo and a defined fanout value
    // OR2_FANOUT is not defined in the provided code, but AND2_FANOUT is defined in Defs.H
    // Use AND2_FANOUT as the default fanout for 2-input gates
    return new OR2(*this);
}

string OR2::GetType() const
{
	return  "OR2"; 
}

bool OR2::IsInside(int x, int y) const
{
	return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 &&
		y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);

	
}
