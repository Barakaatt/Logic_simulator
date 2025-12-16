void LED::operate()
{
	if (m_InputPin.getStatus() == HIGH)
		m_Status = ON;
	else
		m_Status = OFF;
}
	