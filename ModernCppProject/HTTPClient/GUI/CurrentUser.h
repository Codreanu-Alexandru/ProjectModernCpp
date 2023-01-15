#pragma once
#include <string>
#include <cpr/cpr.h>
#include <crow.h>

class CurrentUser {

public:

	std::string getUsername() const;
	std::string getMatchHistory() const;
	uint16_t getId() const;

	void setUsername(std::string username);
	void setMatchHistory(std::string matchHistory);
	void setId(int id);

	void createUser(std::string username);

private:

	std::string username;
	std::string matchHistory;
	uint16_t id;
};

