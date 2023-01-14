#include "StartGameHandler.h"

StartGameHandler::StartGameHandler(Game& game, Lobby& lobby)
{
	this->lobby = &lobby;
	this->game = &game;
}

crow::response StartGameHandler::operator()(const crow::request& req) const
{
	/*if (game.running == false) {
		std::vector<Player> players = lobby->getPlayers();
		game = new Game(players);
	}*/

	crow::json::wvalue gameData;
	int mapHeight = static_cast<int>(game->GetMap()->GetHeight());
	std::cout << mapHeight << std::endl;
	int mapWidth = static_cast<int>(game->getMap()->GetWidth());
	gameData["nrPlayers"] = lobby->numberOfPlayers;
	gameData["mapHeight"] = mapHeight;
	gameData["mapWidth"] = mapWidth;

	return crow::response(200, gameData);
}
