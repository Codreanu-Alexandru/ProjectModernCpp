#include <filesystem>
#include <iostream>
#include <memory>
#include <crow.h>

#include "Game.h"
#include "Map.h"
#include "User.h"
//#include "../TriviadorLogger/TriviadorLogger.h"


int main()
{
	//Testing question
	/*Game g;
	std::cout << g.m_questions.size() << std::endl;
	for (int i = 0; i < g.m_questions.size(); i++)
	{
		if (!g.m_questions[i]->GetIsNumericQuestionBoolean())
		{
			MultipleChoiceQuestion* mcq = dynamic_cast<MultipleChoiceQuestion*>(g.m_questions[i]);
			std::cout << mcq->GetQuestion() << std::endl;
			std::cout << mcq->GetAnswer() << std::endl;
			std::vector<WrongAnswers> wrong = mcq->GetChoices();
			for (int i = 0; i < wrong.size(); i++)
			{
				std::cout << wrong[i].m_choise << std::endl;
			}
			std::cout << std::endl;
		}
		else
		{
			SingleNumericQuestion* snq = dynamic_cast<SingleNumericQuestion*>(g.m_questions[i]);
			std::cout << snq->GetQuestion() << std::endl;
			std::cout << snq->GetAnswer() << std::endl;
			std::cout << std::endl;
		}
	}*/
	///////////
	const std::string csvDataFile = "user_dataset.csv";

	UserDB userDatabase;
	if (!userDatabase.InitializeDB(csvDataFile)) {
		std::cout << "Failed to initialize the database!";
		return -1;
	}

	/*Map map(2);
	map.showMap();*/

	userDatabase.displayDatabase();

	Database userDB = userDatabase.getUserDatabase();

	crow::SimpleApp app;

	CROW_ROUTE(app, "/")([]() {
		return "Intial page for app server.";
	});

	CROW_ROUTE(app, "/users")([&userDB]() {
		std::vector<crow::json::wvalue> users_json;
		for (const auto& user : userDB.iterate<User>())
		{
			users_json.push_back(crow::json::wvalue{
				{"id", user.id},
				{"username", user.username},
				{"password", user.password},
				{"matchHistory", user.matchHistory}
				});
		}
		return crow::json::wvalue{ users_json };
	});

	app.port(18080).multithreaded().run();

	return 0;
}