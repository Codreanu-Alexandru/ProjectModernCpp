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
	Map* GetMap() const;
	enum class State : uint8_t
	{
		None,
		BSelection,
		Conquer,
		Duel,
		End
	};
	State GetState() const;
	void bSelection();

private:
	/*Private members*/
	std::vector<Player> m_players;
	std::vector<std::variant<SingleNumericQuestion,MultipleChoiceQuestion>> m_questions;
	std::vector<SingleNumericQuestion> m_numericQuestions;

	Map* m_map;
	State m_state;

	uint16_t m_numberOfPlayers;
	uint16_t m_numberOfRounds;

	/*Private Function*/
	void InitQuestions(uint16_t numberOfPlayers);
};

std::vector<uint8_t> GetRankingFromQuestion(std::vector<std::tuple<uint8_t, std::string, std::string>> closenessVector, std::variant<SingleNumericQuestion, MultipleChoiceQuestion> question);
std::vector<uint8_t> getRanking(std::vector<std::tuple<uint8_t, float, float>> closenessVector);
