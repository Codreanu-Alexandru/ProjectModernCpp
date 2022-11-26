#pragma once
#include <vector>
#include <fstream>
#include <regex>
#include "Map.h"
#include "Player.h"
#include "MultipleChoiceQuestion.h"
#include "SingleNumericQuestion.h"

#include <sqlite_orm/sqlite_orm.h>
namespace sql = sqlite_orm;

class Game
{
public:

	std::vector<Question*> m_questions;
	std::vector<Player> m_players;
	int m_numberOfPlayers;
	int m_numberOfRounds;

public:

	Game();

};

std::vector<Question*> InitQuestions();

inline auto createStorage(const std::string& filename)
{
	return sql::make_storage(
		filename,
		sql::make_table(
			"Question",
			sql::make_column("id", &Question::m_id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("question", &Question::m_question),
			sql::make_column("isNumeric", &Question::m_isNumericQuestion)
		),
		sql::make_table(
			"SingleNumericQuestion",
			sql::make_column("idQuestion", &SingleNumericQuestion::m_idSMQ),
			sql::make_column("answer", &SingleNumericQuestion::m_answer),
			sql::foreign_key(&SingleNumericQuestion::m_idSMQ).references(&Question::m_id)
		),
		sql::make_table(
			"MultipleChoiceQuestion",
			sql::make_column("idQuestion", &MultipleChoiceQuestion::m_idMCQ),
			sql::make_column("answer", &MultipleChoiceQuestion::m_answer),
			sql::foreign_key(&MultipleChoiceQuestion::m_idMCQ).references(&Question::m_id)
		),
		sql::make_table(
			"WrongAnswers",
			sql::make_column("choice",&WrongAnswers::m_choise),
			sql::make_column("idMCQuestion",&WrongAnswers::m_id),
			sql::foreign_key(&WrongAnswers::m_id).references(&MultipleChoiceQuestion::Question::m_id)
		)
	);
}

using Storage = decltype(createStorage(""));

void populateStorage(Storage& storage);