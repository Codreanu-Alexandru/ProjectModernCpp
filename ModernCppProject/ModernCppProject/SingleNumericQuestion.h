#pragma once
#include "Question.h"
#include <limits>

class SingleNumericQuestion :
    public Question
{

public:
    /*Public Constructor*/
    SingleNumericQuestion(const std::string& question,
        int answer,
        uint16_t id);

    /*Public Getters*/
    void SetAnswer(int newAnswer);

    /*Public Setters*/
    int GetAnswer();

    /*Public Overridden Function*/
    float CheckAnswer(const std::string& answer) override;
    std::string ToString() override;

    /*Public Operator Overload*/
    bool operator==(const SingleNumericQuestion& other);

private:
    /*Private members*/
    int m_answer;
};

