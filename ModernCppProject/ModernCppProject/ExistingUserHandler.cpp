#include "ExistingUserHandler.h"

ExistingUserHandler::ExistingUserHandler(Login login)
	:m_login(login)
{
}

crow::response ExistingUserHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body); //id=2&quantity=3&...
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");
	auto passwordIter = bodyArgs.find("password");

	if (usernameIter != end && passwordIter != end)
	{
		m_login.addLoggedInPlayer(usernameIter->second);
	}

	return crow::response(201);
}


