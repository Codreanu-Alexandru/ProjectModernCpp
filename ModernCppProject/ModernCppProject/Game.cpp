#include "Game.h"

Game::Game()
{
	m_players={};
	m_numberOfPlayers = 0;
	m_numberOfRounds = 0;
	InitQuestions();
}

Game::Game(std::vector<Player>& players)
	:m_players(players)
{
	m_numberOfPlayers = players.size();

	m_map = Map(m_numberOfPlayers);

	switch (m_numberOfPlayers)
	{
	case 2:
	{
		m_numberOfRounds = 5;
		break;
	}
	case 3:
	{
		m_numberOfRounds = 4;
		break;
	}
	case 4:
	{
		m_numberOfRounds = 5;
		break;
	}
	default:
		break;
	}

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

	unsigned int idCounter = 0;
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
			if (!state.compare("_MCQ_"))
			{
				auxQuestion = "";
				while (in != "_END_")
				{
					auxQuestion += in;
					auxQuestion += " ";
					input >> in;
				}

			}
			else if (!state.compare("_A_"))
			{
				for (unsigned int i = 0; i < 3; i++)
				{
					std::string auxString = "";
					while (in != "_END_")
					{
						auxString += in;
						auxString += " ";
						input >> in;
					}
					auxVector.push_back(auxString);
					if (i < 2)
					{
						input >> in;
					}
				}
			}
			else if (!state.compare("_RA_"))
			{
				while (in != "_END_")
				{
					auxAnswer += in;
					auxAnswer += "";
					input >> in;
				}

				Question* mcq = new MultipleChoiceQuestion(auxQuestion, auxAnswer, auxVector,idCounter);

				m_questions.push_back(mcq);

				idCounter++;
				auxAnswer = {};
				auxQuestion = {};
				auxVector.clear();
			}
			else if (!state.compare("_SNQ_"))
			{
				auxQuestion = "";
				while (in != "_END_")
				{
					auxQuestion += in;
					auxQuestion += " ";
					input >> in;
				}
			}
			else if (!state.compare("_CA_"))
			{
				auxAnswer = in;
				Question* snq = new SingleNumericQuestion(auxQuestion, std::stoi(auxAnswer),idCounter);

				m_questions.push_back(snq);

				idCounter++;
				auxAnswer = {};
				auxQuestion = {};
				auxVector.clear();
			}
		}
	}

}
