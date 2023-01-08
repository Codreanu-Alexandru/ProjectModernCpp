#include "LobbyHandler.h"

LobbyHandler::LobbyHandler(Lobby &lobby)
	:m_lobby(&lobby)
{
}



crow::response LobbyHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body); //id=2&quantity=3&...
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");

	if (usernameIter != end)
	{
		bool inLobby = false;
		std::vector<Player> playersInLobby = m_lobby->getPlayers();

		for (Player player : playersInLobby) {
			if (player.GetName() == usernameIter->second) {
				inLobby = true;
			}
		}

		if (!inLobby) {
			m_lobby->addPlayerInLobby(usernameIter->second);
		}
		else {
			m_lobby->removePlayerInLobby(usernameIter->second);
		}
	}

	return crow::response(201);
}