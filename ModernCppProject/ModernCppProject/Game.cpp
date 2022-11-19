#include "Game.h"

Game::Game()
{
	m_players={};
	m_numberOfPlayers = 0;
	m_numberOfRounds = 0;
	InitQuestions();
}

void Game::InitQuestions()
{
	std::ifstream input("qna.txt");
	if (!input.is_open())
	{
		std::cerr << "Could not open file." << std::endl;
		return;
	}

	std::regex stateRegex("[_][A-Z]+[_]");
	std::string state;
	std::string in;

	std::string auxQuestion;
	std::vector<std::string> auxVector;
	std::string auxAnswer;

	while (!input.eof())
	{
		input >> in;
		if (std::regex_match(in, stateRegex))
		{
			state = in;
		}
		else
		{
			if (state == "_MCQ_")
			{
				while (in != "_END_")
				{
					auxQuestion += in;
					auxQuestion += " ";
					input >> in;
				}

			}
			else if (state == "_A_")
			{
				auxVector.push_back(in);
				input >> in;
				auxVector.push_back(in);
				input >> in;
				auxVector.push_back(in);
			}
			else if (state == "_RA_")
			{
				auxAnswer = in;
				Question* mcq = new MultipleChoiceQuestion(auxQuestion, auxAnswer, auxVector);
				m_questions.push_back(mcq);
				auxAnswer = {};
				auxQuestion = {};
				auxVector.clear();
			}
			else if (state == "_SNQ_")
			{
				while (in != "_END_")
				{
					auxQuestion += in;
					auxQuestion += " ";
					input >> in;
				}
			}
			else if (state == "_CA_")
			{
				auxAnswer = in;
				Question* snq = new SingleNumericQuestion(auxQuestion, std::stoi(auxAnswer));
				m_questions.push_back(snq);
				auxAnswer = {};
				auxQuestion = {};
				auxVector.clear();
			}
		}
	}
}
