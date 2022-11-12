#pragma once
#include <iostream>
#include <string>
#include <regex>

class Question
{
private:

	std::string m_question;

public:

	Question(std::string question);
	std::string GetQuestion();
	void SetQuestion(std::string);

public:

	virtual bool CheckAnswer(std::string answer);
};

