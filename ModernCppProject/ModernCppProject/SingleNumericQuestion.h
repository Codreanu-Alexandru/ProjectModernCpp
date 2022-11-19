#pragma once
#include "Question.h"
class SingleNumericQuestion :
    public Question
{
private:

    int m_answer;

public:

    SingleNumericQuestion(const std::string& question, int answer);

    void SetAnswer(int newAnswer);
    int GetAnswer();

public:

    bool CheckAnswer(const std::string& answer) override;
};

