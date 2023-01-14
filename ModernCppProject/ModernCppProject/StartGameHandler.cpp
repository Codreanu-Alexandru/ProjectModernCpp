#include "StartGameHandler.h"

StartGameHandler::StartGameHandler(Game& game, Lobby& lobby)
{
	this->lobby = &lobby;
	this->game = &game;
}

crow::response StartGameHandler::operator()(const crow::request& req) const
{

	crow::json::wvalue gameData;
	int mapHeight = static_cast<int>(game->GetMap()->GetHeight());
	std::cout << mapHeight << std::endl;
	int mapWidth = static_cast<int>(game->GetMap()->GetWidth());
	
	std::vector<Player> players = game->getPlayers();
	std::string usernames_unparsed = "";

	for (Player player : players) {
		usernames_unparsed += player.GetName() + " ";
	}

	gameData["usernames_unparsed"] = usernames_unparsed;
	gameData["nrPlayers"] = lobby->numberOfPlayers;
	gameData["mapHeight"] = mapHeight;
	gameData["mapWidth"] = mapWidth;

	return crow::response(200, gameData);
}
