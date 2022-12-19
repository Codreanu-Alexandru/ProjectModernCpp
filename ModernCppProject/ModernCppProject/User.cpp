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


//User UserDB::findUserByUsername(std::string username)
//{
//	for (User user : m_databaseUsers)
//	{
//		if (user.username == username)
//		{
//			return user;
//		}
//	}
//
//	//return ;
//}
