#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "Pin.h"
#include "OutputPin.h" 

class InputPin; // forward declaration

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool m_Selected; //whether the component is selected or not
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	
	GraphicsInfo GetGraphicsInfo() const;
	void SetGraphicsInfo(const GraphicsInfo& G);
	virtual void UpdatePinsPosition(); 
	virtual Component* Clone() const = 0;
	virtual string GetType() const = 0;
	void setselected(bool s)
	{
		m_Selected = s;
	}
	/////////////////////////////////////////////////////// Ahmed's additions /////////////////////////////////////////
	virtual bool Inside(int x, int y);
	virtual OutputPin* GetOutputPin();
	virtual int GetPinNumber();
	virtual GraphicsInfo getcorners();
	virtual InputPin* GetInputPins(int index);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	bool isselected() const
	{
		return m_Selected;
	}
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	void SetLabel(string label)
	{
		m_Label = label;
	}
	string GetLabel() const
	{
		return m_Label;
	}

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual bool IsInside(int x, int y) const = 0;
	virtual void Reset() {}; // Resets the component (if applicable)
	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();

};

#endif
