#include <filesystem>
#include <iostream>
#include <memory>
#include <crow.h>

#include "Game.h"
#include "Map.h"
#include "User.h"
#include "../TriviadorLogger/TriviadorLogger.h"


std::vector<std::string> splitMain(const std::string& str, const std::string& delim)
{
	std::vector<std::string> result;
	size_t startIndex = 0;

	for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, startIndex))
	{
		result.emplace_back(str.begin() + startIndex, str.begin() + found);
		startIndex = found + delim.size();
	}
	if (startIndex != str.size())
		result.emplace_back(str.begin() + startIndex, str.end());
	return result;
}

std::unordered_map<std::string, std::string> parseUrlArgs(const std::string& urlArgs)
{
	if (urlArgs == "") {
		return {};
	}

	std::unordered_map<std::string, std::string> result;
	for (const auto& kvStr : splitMain(urlArgs, "&")) {
		auto kvVector = splitMain(kvStr, "=");
		if (kvVector.size() == 2)
			result[kvVector[0]] = kvVector[1];
	}
	return result;
}

crow::response getUserData(const crow::request& req) 
{
	auto bodyArgs = parseUrlArgs(req.body); //id=2&quantity=3&...
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");
	auto passwordIter = bodyArgs.find("password");
	if (usernameIter != end && passwordIter != end)
	{
		std::cout << usernameIter->second;

	}

	return crow::response(201);
}


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
			std::vector<std::string> wrong = mcq->GetChoices();
			for (int i = 0; i < wrong.size(); i++)
			{
				std::cout << wrong[i]<< std::endl;
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
		return "Initial starting page for app server.";
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

	auto& sendUserToServerPut = CROW_ROUTE(app, "/sendUserToServer")
		.methods(crow::HTTPMethod::PUT); // https://stackoverflow.com/a/630475/12388382
	sendUserToServerPut(getUserData);


	app.port(4960).multithreaded().run();

	return 0;
}