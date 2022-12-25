#pragma once
#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>
#include <cpr/cpr.h>
#include <crow.h>

bool correctAuthentication(std::string username, std::string password);
bool existingUser(std::string username);
void showUsers();

class ClientInfo {

};

