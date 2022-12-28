#pragma once
#include <iostream>
#include <string>
#include <cstdint>

class Question
{
public:
	/*Public Constructor*/
	Question(const std::string& question, bool isNumericQuestion, int id);

	/*Public Getters*/
	std::string GetQuestion();
	bool GetIsNumericQuestionBoolean();

	/*Public Setters*/
	void SetQuestion(const std::string& newQuestion);

	/*Public Virtual Function*/
	virtual float CheckAnswer(const std::string& answer);

private:
	/*Private members*/
	int m_id;
	bool m_isNumericQuestion;
	std::string m_question;

};

