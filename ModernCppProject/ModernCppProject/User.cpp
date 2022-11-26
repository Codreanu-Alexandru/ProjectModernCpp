#include "User.h"

std::vector<std::string> split(const std::string& str, const std::string& delim) {

	std::vector<std::string> result;
	size_t startIndex = 0;

	for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, startIndex)) {

		result.emplace_back(str.begin() + startIndex, str.begin() + found);
		startIndex = found + delim.size();
	}

	if (startIndex != str.size())
		result.emplace_back(str.begin() + startIndex, str.end());

	return result;
}

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

void UserDB::PopulateDatabase(const std::string& dataFilePath) {

	/*std::ifstream in(dataFilePath);
	std::string str;

	const std::string delim{ "," };
	std::vector<User> users;

	while (std::getline(in, str)) {
		//ID,Username,Password,MatchHistory

		std::vector<std::string> result = split(str, delim);
		users.emplace_back(User{ -1, result[1], result[2], result[3] });
	}

	m_Database.insert_range(users.begin(), users.end());*/

	std::vector<User> products = {
		User{ -1, "Alin", "hohoho222", "" },
		User{ -1, "Florin", "ahahah123", ""}
	};

	m_Database.insert_range(products.begin(), products.end());
}
