#pragma once
#include "Question.h"

class SingleNumericQuestion :
    public Question
{

public:
    /*Public Constructor*/
    SingleNumericQuestion(const std::string& question,
        int answer,
        int id);

    /*Public Getters*/
    void SetAnswer(int newAnswer);

    /*Public Setters*/
    int GetAnswer();

    /*Public Overridden Function*/
    float CheckAnswer(const std::string& answer) override;

    /*Public Operator Overload*/
    bool operator==(const SingleNumericQuestion& other);

private:
    /*Private members*/
    int m_answer;
};

