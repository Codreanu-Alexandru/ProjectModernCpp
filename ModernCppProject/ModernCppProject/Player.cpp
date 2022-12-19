#include "Player.h"

Player::Player(std::string username)
{
	m_name = username;
	m_score = 0;
}

std::string Player::getName()
{
	return m_name;
}
