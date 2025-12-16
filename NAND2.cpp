#include "Defs.H" // Add this include at the top of the file to get access to NAND2_FANOUT
#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NAND2::Operate()
{
	// Calculate the output status as the NAND of the two input pins
	STATUS in1 = m_InputPins[0].getStatus();
	STATUS in2 = m_InputPins[1].getStatus();

	if (in1 == HIGH && in2 == HIGH)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input AND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo);
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Component* NAND2::Clone() const
{
	return new NAND2(m_GfxInfo, NAND2_FANOUT);
}

string NAND2::GetType() const
{
	return "NAND2";
}

bool NAND2::IsInside(int x, int y) const
{
	return (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 &&
		y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2);

}
/*-void NAND2::Reset()
{
	// Reset the output pin to LOW
	m_OutputPin.setStatus(LOW);
}*/