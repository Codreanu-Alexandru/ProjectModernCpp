#include "MultipleChoiceQuestion.h"

MultipleChoiceQuestion::MultipleChoiceQuestion(std::string question, std::string answer, std::vector<std::string> wrongAnswers) :
	Question(question), m_answer(answer), m_wrongAnswers(wrongAnswers)
{
}

bool MultipleChoiceQuestion::CheckAnswer(std::string answer)
{
	return answer == m_answer;
}
