#include "Game.h"

Game::Game()
{
	m_players = {};
	m_numberOfPlayers = 0;
	m_numberOfRounds = 0;
	m_map = new Map(0);
	//InitQuestions(0);
	m_state = State::None;
}

SingleNumericQuestion Game::GetNumericQuestion()
{
	auto question = m_numericQuestions.back();
	m_numericQuestions.pop_back();
	return question;
}

std::variant<SingleNumericQuestion, MultipleChoiceQuestion> Game::GetQuestion()
{
	auto question = m_questions.back();
	m_questions.pop_back();
	return question;
}

Map* Game::GetMap() const
{
	return m_map;
}

Game::State Game::GetState() const
{
	return m_state;
}

void Game::bSelection()
{
	m_state = State::BSelection;
}

void Game::InitQuestions(uint16_t numberOfPlayers)
{
	uint16_t numberOfQuestions;
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
	std::vector<SingleNumericQuestion> numericQuestions;
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
				numericQuestions.push_back(q2);

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
			if (q._Storage()._Get() == auxElement._Storage()._Get())
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

	std::uniform_int_distribution<int> newDistribution(0, numericQuestions.size() - 1);
	uint8_t numberOfNumericQuestions = 6;
	while (numberOfNumericQuestions)
	{
		bool found = false;
		int index = newDistribution(generator);
		auto auxElement = numericQuestions[index];

		for (const auto& q : m_numericQuestions)
		{
			if (auxElement == q)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			m_numericQuestions.emplace_back(auxElement);
			numberOfNumericQuestions--;
		}
	}
}

void Game::setInfo(std::vector<Player> players) {

	m_numberOfPlayers = players.size();
	int mapSizeForTest = m_numberOfPlayers;//just for testing the app without releasing 
	m_map = new Map(mapSizeForTest);
	m_players = players;
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

std::vector<uint8_t> getRanking(std::vector<std::tuple<uint8_t, float, float>> closenessVector)
{
	std::vector<std::tuple<uint8_t, float, float>> diferences;
	std::vector<uint8_t> ranking;

	for (const auto& i : closenessVector)
	{
		auto& [id, answerCloseness, timeStamp] = i;
		diferences.emplace_back(id, std::fabs(answerCloseness - 1.0f), timeStamp);
	}

	std::sort(diferences.begin(), diferences.end(),
		[](const std::tuple<int, float, float> a, const std::tuple<int, float, float>& b) {
			auto& [idA, answerClosenessA, timeStampA] = a;
			auto& [idB, answerClosenessB, timeStampB] = b;
			if (answerClosenessA == answerClosenessB)
			{
				return timeStampA < timeStampB;
			}
			else
			{
				return answerClosenessA < answerClosenessB;
			}
		});

	for (const auto& i : diferences)
	{
		auto& [id, answerCloseness, timeStamp] = i;
		ranking.push_back(id);
	}

	return ranking;
}


std::vector<Player> Game::getPlayers() const
{
	return m_players;
}

std::vector<uint8_t> GetRankingFromQuestion(std::vector<std::tuple<uint8_t, std::string, std::string>> closenessVector,
	std::variant<SingleNumericQuestion, MultipleChoiceQuestion> question)
{
	bool isNumeric = std::holds_alternative<SingleNumericQuestion>(question);
	std::vector<std::tuple<uint8_t, float, float>> realClosenessVector;

	for (auto& cv : closenessVector)
	{
		auto& [id, answerString, timeStamp] = cv;
		if (isNumeric)
		{
			realClosenessVector.push_back({ id,
				std::get<SingleNumericQuestion>(question).CheckAnswer(answerString),
				std::stof(timeStamp) });
		}
		else
		{
			realClosenessVector.push_back({ id,
				std::get<MultipleChoiceQuestion>(question).CheckAnswer(answerString),
				std::stof(timeStamp) });
		}
	}

	return getRanking(realClosenessVector);
}