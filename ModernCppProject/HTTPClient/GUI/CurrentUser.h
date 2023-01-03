#pragma once
#include <string>
#include <cpr/cpr.h>
#include <crow.h>

class CurrentUser {

public:

	std::string getUsername();
	std::string getMatchHistory();
	void setUsername(std::string username);
	void setMatchHistory(std::string matchHistory);

	void createUser(std::string username);

private:

	std::string username;
	std::string matchHistory;
};

