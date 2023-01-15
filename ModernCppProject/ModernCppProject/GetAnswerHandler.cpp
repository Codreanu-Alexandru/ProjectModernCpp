#include "GetAnswerHandler.h"


GetAnswerHandler::GetAnswerHandler(std::vector<std::tuple<uint8_t, float, float>>& answers)
{
	m_answers = &answers;
}

void GetAnswerHandler::operator()(const crow::request& req, crow::response& res, int userId) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto answerIter = bodyArgs.find("answer");
	auto timeIter = bodyArgs.find("time");
	if (answerIter != end && timeIter != end)
	{
		float answer = std::stof(answerIter->second);
		float time = std::stof(timeIter->second);
		std::cout << answer<<std::endl;
		std::cout << time << std::endl;
		m_answers->emplace_back(std::tuple<uint8_t, float, float>(userId, answer, time));
		res.code = 200;
		res.end();
	}
	else
	{
		res.code = 500;
		res.end();
	}

}
