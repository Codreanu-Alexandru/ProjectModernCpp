#pragma once
#include "User.h"
#include "Player.h"
#include <vector>
#include <crow.h>
#include "Login.h"

class ExistingUserHandler
{
public:
	/*Public Constructor*/
	ExistingUserHandler(Login login);

	/*Operator overload*/
	crow::response operator() (const crow::request& req) const;

	/*Public Functions*/
	//void addLoggedInPlayer(std::string username, Login login);

private:
	/*Private members*/
	std::vector<Player> m_loggedInPlayers;
	mutable Login m_login;


};

