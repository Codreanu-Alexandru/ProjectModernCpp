#pragma once
#include "Player.h"

class Login
{
public:
	std::vector<Player> m_loggedInPlayers;

public:
	void addLoggedInPlayer(std::string username);

};

