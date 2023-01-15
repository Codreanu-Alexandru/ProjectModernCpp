#include "AuthUtils.h"

bool correctAuthentication(std::string username, std::string password, cpr::Response response) {

    Encoder encoder;
    auto users = crow::json::load(response.text);
    for (const auto& user : users) {

        if (user["username"].s() == username) {

            if (encoder.TryToMatch(password, user["password"].s())) 
            {
                return true;
            }
        }
    }

    return false;
}

bool existingUser(std::string username, cpr::Response response) {

    auto users = crow::json::load(response.text);
    for (const auto& user : users) {

        if (user["username"].s() == username) {
            return true;
        }
    }

    return false;
}

void showUsers(cpr::Response response) {

    std::cout << "Here is the list of Users(just for now):\n";

    auto users = crow::json::load(response.text);
    for (const auto& user : users) {
        std::cout << user["id"] << ' '
            << user["username"].s() << ' '
            << user["password"] << ' '
            << user["matchHistory"] << '\n';
    }
}

std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> result;
    size_t startIndex = 0;

    for (size_t found = str.find(delim); found != std::string::npos; found = str.find(delim, startIndex))
    {
        result.emplace_back(str.begin() + startIndex, str.begin() + found);
        startIndex = found + delim.size();
    }

    if (startIndex != str.size())
        result.emplace_back(str.begin() + startIndex, str.end());

    return result;
}

