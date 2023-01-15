#pragma once
#include "Player.h"

class Login
{
public:
	/*Public members*/
	/*TBM*/
	std::vector<Player> m_loggedInPlayers;

	/*Public Constructor*/
	void addLoggedInPlayer(std::string username);
};

