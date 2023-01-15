#pragma once
#include <iostream>
#include <string>
#include <cstdint>

class Question
{
public:
	/*Public Constructor*/
	Question(const std::string& question, bool isNumericQuestion, uint16_t id);

	/*Public Getters*/
	std::string GetQuestion() const;
	bool GetIsNumericQuestionBoolean() const;

	/*Public Setters*/
	void SetQuestion(const std::string& newQuestion);

	/*Public Virtual Function*/
	virtual float CheckAnswer(const std::string& answer);
	virtual std::string ToString();

private:
	/*Private members*/
	uint16_t m_id;
	bool m_isNumericQuestion;
	std::string m_question;
};

