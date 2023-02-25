#include "Player.h"

Player::Player() :
	m_name("Player"),
	m_isFirst(true),
	m_signUsed(Sign::X)
{
}

Player::Player(const std::string& name, Sign signUsed = Sign::X, bool isFirst = true, bool isRobot = false) :
	m_name(name),
	m_signUsed(signUsed),
	m_isFirst(isFirst),
	m_isRobot(isRobot)
{
}

Sign Player::GetSignUsed() const
{
	return m_signUsed;
}

std::string Player::GetNameUsed() const
{
	return m_name;
}

bool Player::GetIsFirst() const
{
	return m_isFirst;
}

bool Player::GetIsRobot() const
{
	return m_isRobot;
}

void Player::SetName(const std::string& name)
{
	m_name = name;
}

void Player::SetSignUsed(Sign sign)
{
	m_signUsed = sign;
}

void Player::SetIsFirst(bool isFirst)
{
	m_isFirst = isFirst;
}
