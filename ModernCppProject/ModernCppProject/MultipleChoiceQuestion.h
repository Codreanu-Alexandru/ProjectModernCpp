#pragma once
#include "Question.h"
#include <vector>
class MultipleChoiceQuestion :
    public Question
{
private:

    std::string m_answer;
    std::vector<std::string> m_wrongAnswers;

public:

    MultipleChoiceQuestion(std::string question, std::string answer, std::vector<std::string> wrongAnswers);
    bool CheckAnswer(std::string answer) override;
};

