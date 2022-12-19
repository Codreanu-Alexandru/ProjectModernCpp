#pragma once
#include "User.h"
#include "Player.h"
#include <vector>
#include <crow.h>
#include "Login.h"

class ExistingUserHandler
{
private:
	std::vector<Player> m_loggedInPlayers;
	mutable Login m_login;
public:
	ExistingUserHandler(Login login);
	crow::response operator() (const crow::request& req) const;
	//void addLoggedInPlayer(std::string username, Login login);


};

