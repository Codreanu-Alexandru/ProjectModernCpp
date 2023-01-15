#include "Lobby.h"

Lobby::Lobby(crow::SimpleApp& app)
{
	this->app = &app;
	m_numberOfPlayers = 0; //just for testing the app without releasing
	m_timerSeconds = 15;
}

void Lobby::addPlayerInLobby(std::string username)
{
	m_playersInLobby.emplace_back(Player(username));
	m_numberOfPlayers++;
	m_timerSeconds = 15;
}

void Lobby::removePlayerInLobby(std::string username)
{
	for (size_t indexPlayer = 0; indexPlayer < m_playersInLobby.size(); indexPlayer++) {
		if (m_playersInLobby[indexPlayer].GetName() == username) {
			m_playersInLobby.erase(m_playersInLobby.begin() + indexPlayer);
		}
	}
	m_numberOfPlayers--;
}

void Lobby::flush() {

	m_playersInLobby.clear();
	m_numberOfPlayers = 0;
}

void Lobby::decreaseTimer()
{
	m_timerSeconds--;
}

uint8_t Lobby::getPlayerCount() const
{
	return m_numberOfPlayers;
}

uint8_t Lobby::getTimerSeconds() const
{
	return m_timerSeconds;
}

std::vector<Player> Lobby::getPlayers() const
{
	return m_playersInLobby;
}

