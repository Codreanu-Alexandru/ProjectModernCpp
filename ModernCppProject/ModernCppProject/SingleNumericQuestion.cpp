#include "SingleNumericQuestion.h"

SingleNumericQuestion::SingleNumericQuestion(const std::string& question, int answer, int id) :
	Question(question, true, id), m_answer(answer)
{
}

int SingleNumericQuestion::GetAnswer()
{
	return m_answer;
}

void SingleNumericQuestion::SetAnswer(int newAnswer)
{
	m_answer = newAnswer;
}

float SingleNumericQuestion::CheckAnswer(const std::string& answer)
{
	return static_cast<float>(std::stoi(answer)) / m_answer;
}

bool SingleNumericQuestion::operator==(const SingleNumericQuestion& other)
{
	if (other.m_answer == m_answer)
	{
		return true;
	}
	else
	{
		return false;
	}
}
