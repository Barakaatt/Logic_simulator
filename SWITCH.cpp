void SWITCH::Operate()
{
	if (m_State == ON)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}