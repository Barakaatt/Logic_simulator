#include "Connection.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, Component* pS, Component* pD, int Pin)
	:Component(r_GfxInfo)
	
{
	//SrcPin = pSrcPin;
	//DstPin = pDstPin;
	SrcCmpnt = pS;
	DstCmpnt = pD;
	PinNumber = Pin;
}
Connection::Connection(Component* pS, Component* pD, int Pin)
{
	//SrcPin = NULL;
	DstPin = NULL;
	SrcCmpnt = pS;
	DstCmpnt = pD;
	PinNumber = Pin;
}
/*void Connection::setSourcePin(OutputPin* pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}
*/

int Connection::GetNumOfInputs() {
	return 0; //check this
}
void Connection::DrawFrame(Output* pOut)
{
}


/*void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}



void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}

int Connection::GetPinNumber()
{
	return 0;
}

int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}*/

Component* Connection::Clone() const
{
	return nullptr;
}


string Connection::GetType() const
{
	return string();
}


/*bool Connection::CanConnect()
{
	if (SrcPin && DstPin) {
		if (DstPin->getConnected() == false) {
			if (SrcPin->ConnectTo(this)) {
				DstPin->setConnected(1);
				return true;
			}
		}
	}
	return false;
}*/