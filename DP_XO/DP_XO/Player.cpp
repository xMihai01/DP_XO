#include "Player.h"

Player::Player() :
	m_name("Player"),
	m_signUsed(Sign::X)
{
}

Player::Player(const std::string& name, Sign signUsed = Sign::X) :
	m_name(name),
	m_signUsed(signUsed)
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

void Player::SetName(const std::string& name)
{
	m_name = name;
}

void Player::SetSignUsed(Sign sign)
{
	m_signUsed = sign;
}
