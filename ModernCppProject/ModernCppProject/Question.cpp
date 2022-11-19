#include "Question.h"

Question::Question(const std::string& question, bool isNumericQuestion) :
	m_question(question), m_isNumericQuestion(isNumericQuestion)
{
}

std::string Question::GetQuestion()
{
	return m_question;
}

void Question::SetQuestion(const std::string& newQuestion)
{
	m_question = newQuestion;
}

bool Question::GetIsNumericQuestionBoolean()
{
	return m_isNumericQuestion;
}

bool Question::CheckAnswer(const std::string& answer)
{
	std::cerr << "(!)" << "Something went wrong." << std::endl;
	return false;
}