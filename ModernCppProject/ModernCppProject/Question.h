#pragma once
#include <iostream>
#include <string>
#include <cstdint>

class Question
{
private:

	std::string m_question;
	bool m_isNumericQuestion;

public:

	Question(const std::string& question, bool isNumericQuestion);

	std::string GetQuestion();
	void SetQuestion(const std::string& newQuestion);

	bool GetIsNumericQuestionBoolean();

public:

	virtual bool CheckAnswer(const std::string& answer);
};

