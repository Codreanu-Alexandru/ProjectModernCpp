#pragma once
#include "Question.h"
class SingleNumericQuestion :
    public Question
{
private:

    int m_answer;

public:

    SingleNumericQuestion(std::string question, int answer);
    bool CheckAnswer(std::string answer) override;
};

