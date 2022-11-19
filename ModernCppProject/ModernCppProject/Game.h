#pragma once
#include <vector>
#include <fstream>
#include <regex>
#include "Map.h"
#include "Player.h"
#include "MultipleChoiceQuestion.h"
#include "SingleNumericQuestion.h"

class Game
{
public:

	std::vector<Question*> m_questions;
	std::vector<Player> m_players;
	int m_numberOfPlayers;
	int m_numberOfRounds;

public:

	Game();
	void InitQuestions();

};

