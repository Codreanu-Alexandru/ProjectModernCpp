#include "Lobby.h"

Lobby::Lobby(crow::SimpleApp& app)
{
	this->app = &app;
	numberOfPlayers = 0;
	timerSeconds = 30;
}

void Lobby::addPlayerInLobby(std::string username)
{
	m_playersInLobby.emplace_back(Player(username));
	numberOfPlayers++;
	timerSeconds = 30;
}

void Lobby::removePlayerInLobby(std::string username)
{
	for (size_t indexPlayer = 0; indexPlayer < m_playersInLobby.size(); indexPlayer++) {
		if (m_playersInLobby[indexPlayer].GetName() == username) {
			m_playersInLobby.erase(m_playersInLobby.begin() + indexPlayer);
		}
	}
	numberOfPlayers--;
}

std::vector<Player> Lobby::getPlayers() {
	return m_playersInLobby;
}

void Lobby::flush() {

	m_playersInLobby.clear();
	numberOfPlayers = 0;
}

