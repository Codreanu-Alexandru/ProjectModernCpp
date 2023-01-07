#pragma once
#include "Player.h"
#include <crow.h>

class Lobby
{
public:
	int numberOfPlayers;
	int timerSeconds;
	crow::SimpleApp* app;
	/*Public Constructor*/
	Lobby(crow::SimpleApp &app);
	void addPlayerInLobby(std::string username);
private:
	std::vector<Player> m_playersInLobby;


};



