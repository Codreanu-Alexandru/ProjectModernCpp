#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>

#include <cpr/cpr.h>
#include <crow.h>

void showUsers(cpr::Response response)
{
    std::cout << "Here is the list of Users(just for now):\n";

    auto users = crow::json::load(response.text);
    for (const auto& user : users) {
        std::cout << user["id"] << ' '
            << user["username"].s() << ' '
            << user["password"] << ' '
            << user["matchHistory"] << '\n';
    }
}

void createUser()
{

}


int  main()
{
    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/users" });
    showUsers(response);
    

    std::cout << "Bye!";


    return 0;
}
