#include "Question.h"

Question::Question(const std::string& question, bool isNumericQuestion, uint16_t id = -1) :
	m_question(question), m_isNumericQuestion(isNumericQuestion), m_id(id)
{
}

std::string Question::GetQuestion() const
{
	return m_question;
}

bool Question::GetIsNumericQuestionBoolean() const
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

std::string Question::ToString()
{
	std::cerr << "How did we get here?" << std::endl;
	return { "" };
}
