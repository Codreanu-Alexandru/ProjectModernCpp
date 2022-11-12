#include "Question.h"

Question::Question(std::string question) :
	m_question(question)
{
}

std::string Question::GetQuestion()
{
	return m_question;
}

void Question::SetQuestion(std::string question)
{
	m_question = question;
}

bool Question::CheckAnswer(std::string)
{
	std::cerr << "(!)" << "Something went wrong." << std::endl;
	return false;
}