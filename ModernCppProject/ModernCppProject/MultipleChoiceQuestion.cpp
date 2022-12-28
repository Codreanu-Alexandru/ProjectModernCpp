#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(
	const std::string& question,
	const std::string& answer,
	const std::vector<std::string>& wrongAnswers,
	int id) :
	Question(question, false, id), m_answer(answer), m_wrongChoices(wrongAnswers)
{
}

std::string MultipleChoiceQuestion::GetAnswer()
{
	return m_answer;
}

std::vector<std::string> MultipleChoiceQuestion::GetChoices()
{
	return m_wrongChoices;
}

void MultipleChoiceQuestion::SetAnswer(const std::string& newAnswer)
{
	m_answer = newAnswer;
}

void MultipleChoiceQuestion::SetChoices(const std::vector<std::string>& choices)
{
	m_wrongChoices = choices;
}

float MultipleChoiceQuestion::CheckAnswer(const std::string& answer)
{
	return (answer == m_answer) ? 1.0 : 0.0;
}

bool MultipleChoiceQuestion::operator==(const MultipleChoiceQuestion& other)
{
	if (other.m_answer == m_answer &&
		other.m_wrongChoices == m_wrongChoices)
	{
		return true;
	}
	else
	{
		return false;
	}
}
