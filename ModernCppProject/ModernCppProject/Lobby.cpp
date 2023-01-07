#include "Lobby.h"

Lobby::Lobby(crow::SimpleApp& app)
{
	this->app = &app;
	numberOfPlayers = 1;
	timerSeconds = 30;
}

void Lobby::addPlayerInLobby(std::string username)
{
	m_playersInLobby.emplace_back(Player(username));
	numberOfPlayers++;
	timerSeconds = 30;
}

