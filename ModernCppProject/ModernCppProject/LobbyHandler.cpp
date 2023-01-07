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
		m_lobby->addPlayerInLobby(usernameIter->second);
	}

	return crow::response(201);
}