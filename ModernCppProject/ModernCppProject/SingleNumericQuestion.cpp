#include "SingleNumericQuestion.h"

SingleNumericQuestion::SingleNumericQuestion(std::string question, int answer) :
	Question(question), m_answer(answer)
{
}

bool SingleNumericQuestion::CheckAnswer(std::string answer)
{
	return std::stof(answer) == m_answer;
}
