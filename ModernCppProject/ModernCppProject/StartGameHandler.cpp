#include "StartGameHandler.h"

StartGameHandler::StartGameHandler(Game& game, Lobby& lobby)
{
	this->lobby = &lobby;
	this->game = &game;
}

crow::response StartGameHandler::operator()(const crow::request& req) const
{

	crow::json::wvalue gameData;
	
	std::string usernames_unparsed = "";
	for (Player player : game->getPlayers()) {
		usernames_unparsed += player.GetName() + " ";
	}

	/*Initializing the data to send to the client*/
	gameData["usernames_unparsed"] = usernames_unparsed;
	gameData["nrPlayers"] = lobby->getPlayerCount();
	gameData["mapWidth"] = static_cast<int>(game->GetMap()->GetWidth());
	gameData["mapHeight"] = static_cast<int>(game->GetMap()->GetHeight());

	game->changeState(1);

	return crow::response(200, gameData);
}
