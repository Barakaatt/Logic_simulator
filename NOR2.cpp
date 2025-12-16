#include "NOR2.h"

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR2::Operate()
{
	//caclulate the output status as the NORing of the two input pins
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
	
}


// Function Draw
// Draws 2-input AND gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Component* NOR2::Clone() const
{
    return new NOR2(m_GfxInfo, NOR2_FANOUT);
}

string NOR2::GetType() const
{
	return "NOR2";
}
bool NOR2::IsInside(int x, int y) const
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

