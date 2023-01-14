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
	Game(std::vector<Player>& players);
	Game(std::vector<Player> players);
	Game();

	/*Public functions*/
	SingleNumericQuestion GetNumericQuestion();
	std::variant<SingleNumericQuestion, MultipleChoiceQuestion> GetQuestion();

	/*Setters*/
	void setInfo(std::vector<Player> players);

	/*Getters*/
	std::vector<Player> getPlayers();
	Map* GetMap();

private:
	/*Private members*/
	int m_numberOfPlayers;
	int m_numberOfRounds;
	std::vector<Player> m_players;
	std::vector<std::variant<SingleNumericQuestion,MultipleChoiceQuestion>> m_questions;
	std::vector<SingleNumericQuestion> m_numericQuestions;
	Map* m_map;

	/*Private Function*/
	void InitQuestions(uint8_t numberOfPlayers);
};

std::vector<uint8_t> getRanking(std::vector<std::tuple<int, float, float>> closenessVector);
