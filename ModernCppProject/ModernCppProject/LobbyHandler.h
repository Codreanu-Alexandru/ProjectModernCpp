#pragma once
#include "User.h"
#include "Player.h"
#include <vector>
#include <crow.h>
#include "Lobby.h"

class LobbyHandler
{
public:
	/*Public Constructor*/
	LobbyHandler(Lobby &lobby);

	/*Operator overload*/
	crow::response operator() (const crow::request& req) const;

	/*Public Functions*/
	//void addLoggedInPlayer(std::string username, Login login);

private:
	/*Private members*/
	std::vector<Player> m_playersInLobby;
	mutable Lobby *m_lobby;


};
