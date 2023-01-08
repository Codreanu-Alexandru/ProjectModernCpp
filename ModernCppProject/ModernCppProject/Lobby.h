#pragma once
#include "Player.h"
#include <crow.h>

class Lobby
{

public:
	Lobby(crow::SimpleApp& app);
	void addPlayerInLobby(std::string username);
	void removePlayerInLobby(std::string username);
	std::vector<Player> getPlayers();
	void flush();

public:
	int numberOfPlayers;
	int timerSeconds;
	crow::SimpleApp* app;
	/*Public Constructor*/

private:
	std::vector<Player> m_playersInLobby;
};



