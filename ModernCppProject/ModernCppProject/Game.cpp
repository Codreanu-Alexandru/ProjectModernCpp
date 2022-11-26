#include "Game.h"

Game::Game()
{
	m_players={};
	m_numberOfPlayers = 0;
	m_numberOfRounds = 0;
	//TO DO: question database populating
	m_questions = InitQuestions();

}
std::vector<Question*> InitQuestions()
{
	std::ifstream input("qna.txt");
	if (!input.is_open())
	{
		std::cerr << "Could not open file." << std::endl;
		return{};
	}

	std::regex stateRegex("[_][A-Z]+[_]");
	std::string state;
	std::string in;

	std::vector<Question*> questions;
	std::string auxQuestion;
	std::vector<WrongAnswers> auxVector;
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
				WrongAnswers wa;
				wa.m_choise = in;
				auxVector.push_back(wa);
				input >> in;
				wa.m_choise = in;
				auxVector.push_back(wa);
				input >> in;
				wa.m_choise = in;
				auxVector.push_back(wa);
			}
			else if (state == "_RA_")
			{
				auxAnswer = in;
				Question* mcq = new MultipleChoiceQuestion(auxQuestion, auxAnswer, auxVector,-1);
				questions.push_back(mcq);
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
				Question* snq = new SingleNumericQuestion(auxQuestion, std::stoi(auxAnswer),-1);
				questions.push_back(snq);
				auxAnswer = {};
				auxQuestion = {};
				auxVector.clear();
			}
		}
	}

	return questions;
}

void populateStorage(Storage& storage)
{
	std::vector<Question*> questions = InitQuestions();
	
	//How tf do I populate multiple tables :(
}
