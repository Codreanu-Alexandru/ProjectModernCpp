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
	std::vector<Player> getPlayers() const;
	uint8_t getTurn() const;
	Map* GetMap() const;
	enum class State : uint8_t
	{
		None,
		Question,
		BSelection,
		Conquer,
		Duel,
		End
	};
	State GetState() const;
	void changeState(uint8_t state_index);

private:
	/*Private members*/
	std::vector<Player> m_players;
	std::vector<std::variant<SingleNumericQuestion,MultipleChoiceQuestion>> m_questions;
	std::vector<SingleNumericQuestion> m_numericQuestions;

	Map* m_map;
	State m_state;

	uint16_t m_numberOfPlayers;
	uint16_t m_numberOfRounds;
	uint8_t m_turn;

	/*Private Function*/
	void InitQuestions(uint16_t numberOfPlayers);
};

std::vector<int> GetRankingFromQuestion(std::vector<std::tuple<int, std::string, std::string>> closenessVector, std::variant<SingleNumericQuestion, MultipleChoiceQuestion> question);
std::vector<int> getRanking(std::vector<std::tuple<int, float, float>> closenessVector);
