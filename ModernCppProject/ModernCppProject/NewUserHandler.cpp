#include "NewUserHandler.h"

crow::response NewUserHandler::operator()(const crow::request& req) const
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
		newUser.password = passwordIter->second;
		newUser.matchHistory = "0";
	
		Database userDB = userDatabase.getUserDatabase();
		userDB.insert(newUser);
	
		std::cout << "New users count = " << userDatabase.getUserDatabase().count<User>() << std::endl;
	
		return crow::response(201);
}
