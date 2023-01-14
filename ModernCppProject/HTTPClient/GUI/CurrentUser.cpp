#include "CurrentUser.h"

std::string CurrentUser::getUsername()
{
    return username;
}

std::string CurrentUser::getMatchHistory()
{
    return matchHistory;
}

void CurrentUser::setUsername(std::string username)
{
    this->username = username;
}

void CurrentUser::setMatchHistory(std::string matchHistory)
{
    this->matchHistory = matchHistory;
}

void CurrentUser::setId(int id)
{
    this->id = id;
}
int CurrentUser::getId()
{
    return id;
}

void CurrentUser::createUser(std::string username) {

    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:4960/users" });

    auto users = crow::json::load(response.text);
    for (const auto& user : users) {

        if (user["username"].s() == username) {

            setUsername(username);
            setMatchHistory(user["matchHistory"].s());
            setId(user["id"].i());
        }
    }
}
