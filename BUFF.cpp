#include "BUFF.h"

BUFF::BUFF(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFF::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void BUFF::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER2(m_GfxInfo);
}

//returns status of outputpin
int BUFF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Component* BUFF::Clone() const
{
    return new BUFF(m_GfxInfo, BUFF_FANOUT);
}

string BUFF::GetType() const
{
	return "BUFF";
}
bool BUFF::IsInside(int x, int y) const
{
	int left = m_GfxInfo.x1;
	int right = m_GfxInfo.x2;
	int top = m_GfxInfo.y1;
	int bottom = m_GfxInfo.y2;
	return (x >= left && x <= right && y >= top && y <= bottom);
}
void BUFF::Reset()
{
	// Reset the output pin to LOW
	m_OutputPin.setStatus(LOW);
	// Reset all input pins to LOW
	for (int i = 0; i < 1; ++i) // BUFF has only 1 input pin
	{
		m_InputPins[i].setStatus(LOW);
	}
}
