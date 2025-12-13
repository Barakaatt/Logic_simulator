#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
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

