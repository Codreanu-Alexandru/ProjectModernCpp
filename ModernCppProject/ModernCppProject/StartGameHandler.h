#pragma once
#include "Game.h"
#include "Lobby.h"
#include "Player.h"
#include <vector>

class StartGameHandler
{
public:
	StartGameHandler(Game& game, Lobby &lobby);

	crow::response operator() (const crow::request& req) const;
private:
	mutable Game* game;
	mutable Lobby* lobby;
};

