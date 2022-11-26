#pragma once
#include <iostream>
#include <string>
#include <cstdint>

class Question
{
public:

	int m_id;
	std::string m_question;
	bool m_isNumericQuestion;

public:

	Question(const std::string& question, bool isNumericQuestion, int id);

	std::string GetQuestion();
	void SetQuestion(const std::string& newQuestion);

	bool GetIsNumericQuestionBoolean();

public:

	virtual bool CheckAnswer(const std::string& answer);
};

