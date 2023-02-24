#include "Player.h"

Player::Player() :
	m_name("Player")
{
}

Player::Player(std::string name, Sign signUsed = Sign::X, bool isFirst = true) :
	m_name(name),
	m_signUsed(signUsed),
	m_isFirst(isFirst)
{
}

void Player::PlaceSignOnBoard()
{
}

Sign Player::GetSignUsed()
{
	return m_signUsed;
}
