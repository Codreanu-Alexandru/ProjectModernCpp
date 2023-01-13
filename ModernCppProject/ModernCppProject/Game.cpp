#include "Game.h"

Game::Game()
{
	running = false;
	m_players = {};
	m_numberOfPlayers = 0;
	m_numberOfRounds = 0;
	m_map = new Map(0);
	InitQuestions(0);
}

Game::Game(std::vector<Player> players)
	:m_players(players)
{
	running = true;
	m_numberOfPlayers = players.size();
	int mapSizeForTest = m_numberOfPlayers+1;//just for testing the app without releasing 
	m_map = new Map(mapSizeForTest);
	InitQuestions(m_numberOfPlayers);
	switch (m_numberOfPlayers)
	{
	case 2:
	{
		/*2 Players
		5 Rounds*/
		m_numberOfRounds = 5;
		break;
	}
	case 3:
	{
		/*3 Players
		4 Rounds*/
		m_numberOfRounds = 4;
		break;
	}
	case 4:
	{
		/*4 Players
		5 Rounds*/
		m_numberOfRounds = 5;
		break;
	}
	default:
	{
		/*Something went wrong*/
		m_numberOfRounds = 0;
		break;
	}
	}

}

Map* Game::getMap()
{
	return m_map;
}

void Game::InitQuestions(uint8_t numberOfPlayers)
{
	uint8_t numberOfQuestions;
	switch (numberOfPlayers)
	{
	case 2:
	{	/*2 Players - 7 Questions*/
		numberOfQuestions = 14;
		break;
	}
	case 3:
	{
		/* 3 Players - 14 Questions*/
		numberOfQuestions = 28;
		break;
	}
	case 4:
	{
		/*4 Players - 22 Questions*/
		numberOfQuestions = 44;
		break;
	}
	default:
		return;
	}

	std::vector<std::variant<SingleNumericQuestion, MultipleChoiceQuestion>> questions;
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

				auto q1 = MultipleChoiceQuestion(auxQuestion, auxAnswer, auxVector, idCounter);
				questions.push_back(q1);

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

				auto q2 = SingleNumericQuestion(auxQuestion, std::stoi(auxAnswer), idCounter);
				questions.push_back(q2);

				idCounter++;
				auxAnswer = {};
				auxQuestion = {};
				auxVector.clear();
			}
		}
	}

	std::random_device generator;
	std::uniform_int_distribution<int> distribution(0, questions.size() - 1);

	while (numberOfQuestions)
	{
		bool found = false;
		int index = distribution(generator);
		auto auxElement = std::move(questions[index]);

		for (const auto& q : m_questions)
		{
			if (q.index() == auxElement.index())
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			m_questions.emplace_back(auxElement);
			numberOfQuestions--;
		}
	}
}

void Game::setInfo(std::vector<Player> players) {

	running = true;
	m_numberOfPlayers = players.size();
	int mapSizeForTest = m_numberOfPlayers;//just for testing the app without releasing 
	m_map = new Map(mapSizeForTest);
	//InitQuestions(m_numberOfPlayers);
	switch (m_numberOfPlayers)
	{
	case 2:
	{
		/*2 Players
		5 Rounds*/
		m_numberOfRounds = 5;
		break;
	}
	case 3:
	{
		/*3 Players
		4 Rounds*/
		m_numberOfRounds = 4;
		break;
	}
	case 4:
	{
		/*4 Players
		5 Rounds*/
		m_numberOfRounds = 5;
		break;
	}
	default:
	{
		/*Something went wrong*/
		m_numberOfRounds = 0;
		break;
	}
	}
}