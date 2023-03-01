#include "Robot.h"

Robot::Robot() :
	m_name("Robot"),
	m_signUsed(Sign::O)
{
}

Sign Robot::GetSignUsed() const
{
	return m_signUsed;
}

std::string Robot::GetNameUsed() const
{
	return m_name;
}

void Robot::SetName(const std::string& name)
{
	m_name = name;
}

void Robot::SetSignUsed(Sign sign)
{
	m_signUsed = sign;
}