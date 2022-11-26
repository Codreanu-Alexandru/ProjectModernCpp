#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sqlite_orm/sqlite_orm.h>

namespace sql = sqlite_orm;
const std::string databaseFile = "users.sqlite";

struct User {

	int id;
	std::string username;
	std::string password;
	std::string matchHistory;
};

inline auto createStorage(const std::string& filename) {
	return sql::make_storage(
		filename,
		sql::make_table(
			"Books",
			sql::make_column("id", &User::id, sql::autoincrement(), sql::primary_key()),
			sql::make_column("username", &User::username),
			sql::make_column("password", &User::password),
			sql::make_column("matchHistory", &User::matchHistory)
		)
	);
}

using Database = decltype(createStorage(""));

class UserDB {

public:
	bool InitializeDB(const std::string& csvDataFilePath);
	int getNumberOfUsers();

public:
	void displayDatabase();

private:
	void PopulateDatabase(const std::string& dataFilePath);
	Database m_Database = createStorage(databaseFile);
};