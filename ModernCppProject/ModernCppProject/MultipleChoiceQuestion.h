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

    MultipleChoiceQuestion(const std::string& question, const std::string& answer, const std::vector<std::string>& wrongAnswers);

    void SetChoices(const std::vector<std::string>& choices);
    std::vector<std::string> GetChoices();
    void SetAnswer(std::string newAnswer);
    std::string GetAnswer();

public:

    bool CheckAnswer(const std::string& answer) override;
};

