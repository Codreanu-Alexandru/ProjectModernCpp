#include "AuthUtils.h"

bool correctAuthentication(std::string username, std::string password, cpr::Response response) {

    auto users = crow::json::load(response.text);
    for (const auto& user : users) {

        if (user["username"].s() == username) {

            if (user["password"].s() == password) {

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


