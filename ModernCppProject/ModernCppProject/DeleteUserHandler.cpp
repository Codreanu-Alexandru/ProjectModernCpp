#include "DeleteUserHandler.h"

crow::response DeleteUserHandler::operator()(const crow::request& req) const
{
	auto bodyArgs = parseUrlArgs(req.body);
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");

	UserDB userDatabase;
	Database userDB = userDatabase.getUserDatabase();

	for (const auto& user : userDB.iterate<User>())
	{
		if (usernameIter->second == user.username)
		{
			userDB.remove<User>(user.id);
			break;
		}
	}

	std::cout << std::endl<<"User " << usernameIter->second << " has been deleted. New users count = "
		<< userDatabase.getUserDatabase().count<User>() << std::endl;

	return crow::response(201);
}
