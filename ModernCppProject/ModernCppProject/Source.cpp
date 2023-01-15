#include <filesystem>
#include <iostream>
#include <memory>
#include <crow.h>

#include "Game.h"
#include "Map.h"
#include "User.h"
#include "../TriviadorLogger/TriviadorLogger.h"
#include "../Encoder/Encoder.h"
#include "NewUserHandler.h"
#include "ExistingUserHandler.h"
#include "Login.h"
#include "LobbyHandler.h"
#include "Player.h"
#include "Lobby.h"
#include "StartGameHandler.h"
#include "GetAnswerHandler.h"
#include "DeleteUserHandler.h"

int main()
{

	const std::string csvDataFile = "user_dataset.csv";

	UserDB userDatabase;
	if (!userDatabase.InitializeDB(csvDataFile)) {
		std::cout << "Failed to initialize the database!";
		return -1;
	}

	userDatabase.displayDatabase();
	Database userDB = userDatabase.getUserDatabase();

	crow::SimpleApp app;

	Game game;
	Lobby lobby(app);
	Login login;
	std::vector<SingleNumericQuestion> questions;
	std::vector<std::tuple<int, float, float>> answers;

	CROW_ROUTE(app, "/")([]() {
		return "Initial starting page for app server.";
		});

	CROW_ROUTE(app, "/users")([&userDB]() {
		std::vector<crow::json::wvalue> users_json;
	for (const auto& user : userDB.iterate<User>())
	{
		users_json.push_back(crow::json::wvalue{
			{"id", user.id},
			{"username", user.username},
			{"password", user.password},
			{"matchHistory", user.matchHistory}
			});
	}
	return crow::json::wvalue{ users_json };
		});

	ExistingUserHandler existingUser(login);
	auto& sendExistingUserToServerPut = CROW_ROUTE(app, "/sendExistingUserToServer")
		.methods(crow::HTTPMethod::PUT);
	sendExistingUserToServerPut(existingUser);

	auto& sendNewUserToServerPut = CROW_ROUTE(app, "/sendNewUserToServer")
		.methods(crow::HTTPMethod::PUT);
	sendNewUserToServerPut(NewUserHandler());

	auto& deleteUserFromServerPut = CROW_ROUTE(app, "/deleteUserFromServer")
		.methods(crow::HTTPMethod::PUT);
	deleteUserFromServerPut(DeleteUserHandler());

	LobbyHandler lobbyHandler(lobby);
	auto& sendPlayersInLobbyPut = CROW_ROUTE(app, "/sendPlayerInLobbyToServer")
		.methods(crow::HTTPMethod::PUT);
	sendPlayersInLobbyPut(lobbyHandler);

	auto& removePlayersFromLobbyPut = CROW_ROUTE(app, "/removePlayerFromLobby")
		.methods(crow::HTTPMethod::PUT);
	removePlayersFromLobbyPut(lobbyHandler);

	uint16_t code = 500;
	uint16_t requests = 0;
	CROW_ROUTE(app, "/lobbyInfo")([&lobby, &game, &questions, &code, &requests]() {

		crow::json::wvalue lobbyData;

	lobbyData["timerSeconds"] = lobby.getTimerSeconds();
	lobbyData["playersInLobby"] = lobby.getPlayerCount();

	requests++;
	if (requests % lobby.getPlayerCount() == 0) {
		lobby.decreaseTimer();
	}

	std::cout << std::endl;
	std::cout << lobby.getTimerSeconds();

	if (lobby.getPlayerCount() != 4 && lobby.getTimerSeconds() > 0)
		code = 303;
	else if (lobby.getPlayerCount() == 1 && lobby.getTimerSeconds() <= 0) {
		code = 302;
		lobby.flush();
	}
	else if (lobby.getPlayerCount() == 4 || (lobby.getTimerSeconds() <= 0 && lobby.getPlayerCount() > 1)) {
		if (code != 301) {
			game.setInfo(lobby.getPlayers());
			//questions.emplace_back(SingleNumericQuestion("bau question?", 123, 2));
			questions.emplace_back(game.GetNumericQuestion());
			//questions.emplace_back(game.GetNumericQuestion());
			//questions.emplace_back(game.GetNumericQuestion());
		}
		code = 301;
	}

	return crow::response(code, lobbyData);
		});

	StartGameHandler startGame(game, lobby);
	auto& startGamePut = CROW_ROUTE(app, "/startGame")
		.methods(crow::HTTPMethod::PUT);
	startGamePut(startGame);

	CROW_ROUTE(app, "/gameState")([&game]() {
		crow::json::wvalue gameState;
	gameState["State"] = static_cast<int>(game.GetState());
	return crow::response(200, gameState);
		});


	int readyPlayers = 0;
	CROW_ROUTE(app, "/ready")([&game, &readyPlayers]() {
		readyPlayers++;
	std::cout << "Ready players: " << readyPlayers << "\n";

	if (readyPlayers == game.getPlayers().size()) {
		readyPlayers = 0;
		return crow::response(301);
	}
	return crow::response(302);
		});

	/*CROW_ROUTE(app, "/turn")([&game]() {
		
		});*/

	CROW_ROUTE(app, "/numericQ/<int>")([&game, &questions](const crow::request& req, crow::response& res, int questionPos) {
		crow::json::wvalue baseQuestion;
	baseQuestion["question"] = questions[questionPos].ToString();
	baseQuestion["isNumeric"] = questions[questionPos].GetIsNumericQuestionBoolean();
	res = crow::response(200, baseQuestion);
	res.end();
		});

	GetAnswerHandler getAnswer(answers);
	auto& getAnswerPut = CROW_ROUTE(app, "/numericAnswer/<int>")
		.methods(crow::HTTPMethod::PUT);
	getAnswerPut(getAnswer);

	app.port(4960).multithreaded().run();

	return 0;
}