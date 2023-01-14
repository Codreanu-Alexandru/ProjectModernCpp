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
	return (answer == m_answer) ? 1.0f : 0.0f;
}

std::string MultipleChoiceQuestion::ToString()
{
	std::string questionString{ "" };
	questionString += this->GetQuestion();
	questionString += "/";
	questionString += this->GetAnswer();
	questionString += "/";
	for (const auto& wa : m_wrongChoices)
	{
		questionString += wa;
		questionString += "/";
	}

	return questionString;
}

bool MultipleChoiceQuestion::operator==(const MultipleChoiceQuestion& other)
{
	return (other.m_answer == m_answer && other.m_wrongChoices == m_wrongChoices);
}
