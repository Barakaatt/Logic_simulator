#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
    m_Label = "DefaultLabel";
    m_ID = 0;
}

Component::Component()
{}

Component::~Component()
{}

GraphicsInfo Component::GetGraphicsInfo() const
{
    return m_GfxInfo;
}

void Component::SetGraphicsInfo(const GraphicsInfo& G)
{
    m_GfxInfo = G;
}

void Component::UpdatePinsPosition()
{
   
}

int Component::GetPinNumber()
{
    // Default implementation for base class, can be overridden by derived classes.
    // If not applicable, return -1 or 0 as a safe default.
    return -1;
}

