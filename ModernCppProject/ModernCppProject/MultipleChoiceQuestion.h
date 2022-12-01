#pragma once
#include "Question.h"
#include <vector>

class MultipleChoiceQuestion :
    public Question
{
public:

    std::string m_answer;
    std::vector<std::string> m_wrongChoices;

public:

    MultipleChoiceQuestion(
        const std::string& question,
        const std::string& answer,
        const std::vector<std::string>& wrongChoices,
        int id);

    void SetChoices(const std::vector<std::string>& choices);
    std::vector<std::string> GetChoices();

    void SetAnswer(std::string newAnswer);
    std::string GetAnswer();

public:

    bool CheckAnswer(const std::string& answer) override;
};

