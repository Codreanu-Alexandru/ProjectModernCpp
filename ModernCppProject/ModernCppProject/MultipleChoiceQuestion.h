#pragma once
#include "Question.h"
#include <vector>

struct WrongAnswers
{
public:
    int m_id;
    std::string m_choise;
};

class MultipleChoiceQuestion :
    public Question
{
public:

    int m_idMCQ;
    std::string m_answer;
    std::vector<WrongAnswers> m_wrongChoices;

public:

    MultipleChoiceQuestion(
        const std::string& question,
        const std::string& answer,
        const std::vector<WrongAnswers>& wrongChoices,
        int id);

    void SetChoices(const std::vector<WrongAnswers>& choices);
    std::vector<WrongAnswers> GetChoices();
    void SetAnswer(std::string newAnswer);
    std::string GetAnswer();

public:

    bool CheckAnswer(const std::string& answer) override;
};

