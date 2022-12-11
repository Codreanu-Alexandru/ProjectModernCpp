#pragma once
#include <cpr/cpr.h>
#include <crow.h>

bool correctAuthentication(std::string username, std::string password);
bool existingUser(std::string username);
void showUsers();

class AuthentificationUtils
{

};

