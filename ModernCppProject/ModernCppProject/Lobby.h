#pragma once
#include "Player.h"
#include <crow.h>

class Lobby
{

public:
	Lobby(crow::SimpleApp& app);

	/*Lobby handling functions*/
	void addPlayerInLobby(std::string username);
	void removePlayerInLobby(std::string username);
	void flush();
	void decreaseTimer();

	/*Getters*/
	uint8_t getPlayerCount() const;
	uint8_t getTimerSeconds() const;

	std::vector<Player> getPlayers() const;

public:
	crow::SimpleApp* app;

private:
	std::vector<Player> m_playersInLobby;
	uint8_t m_numberOfPlayers;
	uint8_t m_timerSeconds;
};



