#pragma once
#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>
#include <cpr/cpr.h>
#include <crow.h>
#include "CurrentUser.h"
#include "Encoder.h"

bool correctAuthentication(std::string username, std::string password, cpr::Response response);
bool existingUser(std::string username, cpr::Response response);
void showUsers(cpr::Response response);
std::string getCurrentUserUsername();

