#pragma once
#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>
#include <cpr/cpr.h>
#include <crow.h>

//bool correctAuthentication(std::string username, std::string password);
//bool existingUser(std::string username);
//void showUsers();

class ClientInfo {

public:
	ClientInfo();
	~ClientInfo();
	std::vector<std::pair<std::string, std::string> > setUserInfo();
	std::vector<std::pair<std::string, std::string> > getUserInfo();

private:
	cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/users" });
	std::vector<std::pair<std::string, std::string> > userInfos = setUserInfo();
};

