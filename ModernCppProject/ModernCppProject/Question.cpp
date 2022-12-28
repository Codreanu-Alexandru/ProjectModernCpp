#include "Question.h"

Question::Question(const std::string& question, bool isNumericQuestion, int id = -1) :
	m_question(question), m_isNumericQuestion(isNumericQuestion), m_id(id)
{
}

std::string Question::GetQuestion()
{
	return m_question;
}

bool Question::GetIsNumericQuestionBoolean()
{
	return m_isNumericQuestion;
}

void Question::SetQuestion(const std::string& newQuestion)
{
	m_question = newQuestion;
}

float Question::CheckAnswer(const std::string& answer)
{
	std::cerr << "(!)" << "Something went wrong." << std::endl;
	return 0.0;
}