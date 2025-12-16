#ifndef _PIN_H
#define _PIN_H

#include "..\Defs.h"

class Pin
{
protected:
	STATUS m_Status;	//Status of the Pin
public:
	Pin();
	void setStatus(STATUS r_Status);



	void setConnected(bool c);//Barakat
	bool getConnected(); //Barakat




	STATUS getStatus();
};

#endif