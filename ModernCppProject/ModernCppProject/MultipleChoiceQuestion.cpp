#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(const std::string& question, const std::string& answer, const std::vector<std::string>& wrongAnswers) :
	Question(question, false), m_answer(answer), m_wrongAnswers(wrongAnswers)
{
}

void MultipleChoiceQuestion::SetChoices(const std::vector<std::string>& choices)
{
	m_wrongAnswers = choices;
}

std::vector<std::string> MultipleChoiceQuestion::GetChoices()
{
	return m_wrongAnswers;
}

void MultipleChoiceQuestion::SetAnswer(std::string newAnswer)
{
	m_answer = newAnswer;
}

std::string MultipleChoiceQuestion::GetAnswer()
{
	return m_answer;
}

bool MultipleChoiceQuestion::CheckAnswer(const std::string& answer)
{
	return answer == m_answer;
}
