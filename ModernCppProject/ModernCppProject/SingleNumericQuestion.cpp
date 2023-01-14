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
	float auxAnswer = 1.0f;
	float closenessResult = 0.0f;
	try
	{
		auxAnswer = static_cast<float>(std::stoi(answer));
	}
	catch (const std::invalid_argument& exception)
	{
		return std::numeric_limits<float>::min();
	}
	catch (const std::out_of_range& exception)
	{
		return std::numeric_limits<float>::min();
	}

	if (m_answer == 0 && auxAnswer == 0)
	{
		return 1.0f;
	}
	else if (m_answer == 0 && auxAnswer != 0)
	{
		return std::fabs(auxAnswer);
	}

	return auxAnswer / m_answer;
}

std::string SingleNumericQuestion::ToString()
{
	std::string questionString{ "" };
	questionString += this->GetQuestion();
	questionString += "/";
	questionString += std::to_string(this->GetAnswer());
	questionString += "/";

	return questionString;
}

bool SingleNumericQuestion::operator==(const SingleNumericQuestion& other)
{
	return other.m_answer == m_answer;
}
