#include "User.h"


bool UserDB::InitializeDB(const std::string& csvDataFilePath) {
    
	m_Database.sync_schema();

	auto initialUsersCount = m_Database.count<User>();
	if (initialUsersCount == 0) {
		PopulateDatabase(csvDataFilePath);
	}

	auto usersCount = m_Database.count<User>();
	return usersCount != 0;
}

int UserDB::getNumberOfUsers() {
	auto usersCount = m_Database.count<User>();
	return usersCount;
}


void UserDB::displayDatabase() {
	auto usersCount = m_Database.count<User>();
	std::cout << "usersCount = " << usersCount << '\n';
}

Database UserDB::getUserDatabase() {
	return m_Database;
}

void UserDB::PopulateDatabase(const std::string& dataFilePath) {

	std::ifstream in(dataFilePath);
	std::string str;

	const std::string delim{ "," };
	std::vector<User> users;

	while (std::getline(in, str)) {
		//ID,Username,Password,MatchHistory

		std::vector<std::string> result = split(str, delim);
		users.emplace_back(User{ -1, result[1], result[2], result[3] });
	}

	/*m_Database.insert_range(users.begin(), users.end());

	std::vector<User> users = {
		
	};*/

	m_Database.insert_range(users.begin(), users.end());
}


crow::response UserDB::getExistingUserData(const crow::request& req)
{
	auto bodyArgs = parseUrlArgs(req.body); //id=2&quantity=3&...
	auto end = bodyArgs.end();
	auto usernameIter = bodyArgs.find("username");
	auto passwordIter = bodyArgs.find("password");
	m_databaseUsers = m_Database.get_all<User>();


	if (usernameIter != end && passwordIter != end)
	{
		//Player player(findUserByUsername(usernameIter->second));//this to be added in the list of players in game class
		//the relation between player and user needs adjustments in order to save the match history at the end of the game
	}

	return crow::response(201);
}

User UserDB::findUserByUsername(std::string username)
{
	for (User user : m_databaseUsers)
	{
		if (user.username == username)
		{
			return user;
		}
	}

	//return ;
}
