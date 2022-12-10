#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <crow.h>

#include "Game.h"
#include "Map.h"
#include "User.h"
#include "../TriviadorLogger/TriviadorLogger.h"
#include "../PasswordEncoder/Encoder.h"


crow::response getExistingUserData(const crow::request& req)
{
	auto bodyArgs = parseUrlArgs(req.body); //id=2&quantity=3&...
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");
	auto passwordIter = bodyArgs.find("password");

	if (usernameIter != end && passwordIter != end)
	{
		std::cout << "User " << usernameIter->second << " has logged in.\n";

	}

	return crow::response(201);
}

crow::response getNewUserData(const crow::request& req) 
{
	auto bodyArgs = parseUrlArgs(req.body); //id=2&quantity=3&...
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");
	auto passwordIter = bodyArgs.find("password");

	UserDB userDatabase;
	auto usersCount = userDatabase.getUserDatabase().count<User>();

	User newUser;
	newUser.id = usersCount + 1;
	newUser.username = usernameIter->second;
	newUser.password = usernameIter->second;
	newUser.matchHistory = "0";

	Database userDB = userDatabase.getUserDatabase();
	userDB.insert(newUser);

	std::cout << "New users count = " << userDatabase.getUserDatabase().count<User>() << std::endl;

	return crow::response(201);
}


int main()
{
	////Testing Encoder
	//Encoder encoder;

	//std::string stringInput;
	//std::string otherString;

	//std::cout << "Your password: ";
	//std::cin >> stringInput;

	//otherString = encoder.Encode(stringInput, '\0');
	//std::cout << "Is now: " << otherString << std::endl;

	//std::cout << "Try password: ";
	//std::string aux;
	//std::cin >> aux;
	//std::cout << (encoder.TryToMatch(aux, otherString) ? "Yes, it matches." : "No, it doesn't match.");

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
	/////////
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

	auto& sendExistingUserToServerPut = CROW_ROUTE(app, "/sendExistingUserToServer")
		.methods(crow::HTTPMethod::PUT); // https://stackoverflow.com/a/630475/12388382
	sendExistingUserToServerPut(getExistingUserData);

	auto& sendNewUserToServerPut = CROW_ROUTE(app, "/sendNewUserToServer")
		.methods(crow::HTTPMethod::PUT); // https://stackoverflow.com/a/630475/12388382
	sendNewUserToServerPut(getNewUserData);


	app.port(4960).multithreaded().run();

	return 0;
}