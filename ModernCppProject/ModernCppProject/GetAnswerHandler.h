#pragma once
#include <vector>
#include <tuple>
#include <crow.h>
#include "LobbyHandler.h"
#include "Game.h"

class GetAnswerHandler
{
public:
	GetAnswerHandler(std::vector<std::tuple<int, float, float>> &answers, Game& game);

	/*Operator overload*/
	void operator() (const crow::request& req, crow::response& res, int userId) const;
private:
	std::vector<std::tuple<int, float, float>>* m_answers;
	mutable uint8_t m_nrOfAnswers;
	mutable Game* game;
};

