#include "GetAnswerHandler.h"


GetAnswerHandler::GetAnswerHandler(std::vector<std::tuple<int, float, float>>& answers, Game& game)
{
	m_answers = &answers;
	m_nrOfAnswers = 0;
	this->game = &game;
}

void GetAnswerHandler::operator()(const crow::request& req, crow::response& res, int userId) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto answerIter = bodyArgs.find("answer");
	auto timeIter = bodyArgs.find("time");

	if (answerIter != end && timeIter != end)
	{

		float answer = std::stoi(answerIter->second);
		float time = std::stof(timeIter->second);
		std::cout << answer<<std::endl;
		std::cout << time << std::endl;
		m_answers->emplace_back(std::tuple<int, float, float>(userId, answer, time));

		m_nrOfAnswers++;
		if (m_nrOfAnswers == game->getPlayers().size()) {
			game->changeState(2);
		}
		else {
			game->changeState(0);
		}

		res.code = 200;
		res.end();
	}
	else
	{
		res.code = 500;
		res.end();
	}
}
