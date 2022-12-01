#pragma once
#include "Question.h"
class SingleNumericQuestion :
    public Question
{
public:

    int m_answer;

public:

    SingleNumericQuestion(const std::string& question,
        int answer,
        int id);

    void SetAnswer(int newAnswer);
    int GetAnswer();

public:

    bool CheckAnswer(const std::string& answer) override;
};

