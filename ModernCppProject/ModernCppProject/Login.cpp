#include "Login.h"

void Login::addLoggedInPlayer(std::string username)
{
	m_loggedInPlayers.emplace_back(Player(username));
}
