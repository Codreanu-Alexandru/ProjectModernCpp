#include "SingleNumericQuestion.h"

SingleNumericQuestion::SingleNumericQuestion(const std::string& question, int answer, int id = -1) :
	Question(question, true, id), m_answer(answer), m_idSMQ(id)
{
}

void SingleNumericQuestion::SetAnswer(int newAnswer)
{
	m_answer = newAnswer;
}

int SingleNumericQuestion::GetAnswer()
{
	return m_answer;
}

bool SingleNumericQuestion::CheckAnswer(const std::string& answer)
{
	return std::stof(answer) == m_answer;
}
