#include "Player.h"

Player::Player(const std::string& username)
	:m_name(username)
{
	m_isActivPlayer = true;
	m_score = 0;
}

std::string Player::GetName()
{
	return m_name;
}

void Player::SetName(const std::string& username)
{
	m_name = username;
}
