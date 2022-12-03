#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>

#include <cpr/cpr.h>
#include <crow.h>

//void showUsers(cpr::Response response)
//{
//    std::cout << "Here is the list of Users(just for now):\n";
//
//    auto users = crow::json::load(response.text);
//    for (const auto& user : users) {
//        std::cout << user["id"] << ' '
//            << user["username"].s() << ' '
//            << user["password"] << ' '
//            << user["matchHistory"] << '\n';
//    }
//}

bool correctAuthentication(cpr::Response response, std::string username, std::string password) {

    bool foundUsername = false;
    bool foundPassword = false;

    auto users = crow::json::load(response.text);
    for (const auto& user : users) {

        if (user["username"].s() == username) {
            foundUsername = true;

            if (user["password"].s() == password) {
                foundPassword = true;
            }
        }
    }

    if (foundUsername && foundPassword) {
        return true;
    }
    else {
        return false;
    }
}

void createUser()
{

}


int  main()
{
    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:4960/users" });

    //std::cout << "Here is the list of users:\n";

    /*auto users = crow::json::load(response.text);
    for (const auto& user : users) {
        std::cout << user["id"] << ' '
            << user["username"].s() << ' '
            << user["password"].s() << ' '
            << user["matchHistory"].s() << '\n';
    }*/

    std::cout << "Welcome to the home page!\n";

    int option = -1;
    std::string username;
    std::string password;

    do {

        std::cout << "1. Log in\n";
        std::cout << "2. Create an account\n";
        std::cout << "0. Exit\n";

        std::cout << "\nChoose an option: ";
        std::cin >> option;

        switch (option) {
            
        case 1:
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            while (!correctAuthentication(response, username, password)) {

                std::cout << "Incorrect username or password. Try again.\n";
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;
            }

            std::cout << "Logged into your account.\n";

            break;
        case 2:
            std::cout << "Enter an username: ";
            std::cin >> username;
            std::cout << "Enter a password: ";
            std::cin >> password;

            std::cout << "Created account.\n";

            break;

        default:
            std::cout << "Please enter a valid option.\n";

            break;
        }

    } while (option != 0);

    return 0;
}
