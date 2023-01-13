#pragma once
#include <vector>
#include <fstream>
#include <regex>
#include <random>
#include <variant>
#include <algorithm>
#include "Map.h"
#include "Player.h"
#include "MultipleChoiceQuestion.h"
#include "SingleNumericQuestion.h"

class Game
{
public:
	bool running;
public:

	/*Public Constructor*/
	Game();
	Game(std::vector<Player> players);
	void setInfo(std::vector<Player> players);
	Map* getMap();

private:
	/*Private members*/
	int m_numberOfPlayers;
	int m_numberOfRounds;
	std::vector<Player> m_players;
	std::vector<std::variant<SingleNumericQuestion,MultipleChoiceQuestion>> m_questions;
	Map* m_map;

	/*Private Function*/
	void InitQuestions(uint8_t numberOfPlayers);
};
