#pragma once
#include "Question.h"
#include <vector>

class MultipleChoiceQuestion :
    public Question
{
public:
    /*Public Constructor*/
    MultipleChoiceQuestion(
        const std::string& question,
        const std::string& answer,
        const std::vector<std::string>& wrongChoices,
        int id);

    /*Getters*/
    std::string GetAnswer();
    std::vector<std::string> GetChoices();

    /*Setters*/
    void SetAnswer(const std::string& newAnswer);
    void SetChoices(const std::vector<std::string>& choices);

    /*Public Overridden Function*/
    float CheckAnswer(const std::string& answer) override;

    bool operator==(const MultipleChoiceQuestion& other);

private:
    /*Private members*/
    std::string m_answer;
    std::vector<std::string> m_wrongChoices;
};

