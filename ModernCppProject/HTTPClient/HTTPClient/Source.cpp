#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>

#include <cpr/cpr.h>
#include <crow.h>



int  main()
{
    cpr::Response response = cpr::Get(cpr::Url{ "http://localhost:18080/users" });

    std::cout << "Here is the list of Users(just for now):\n";

    auto users = crow::json::load(response.text);
    for (const auto& user : users) {
        std::cout << user["id"] << ' '
            << user["name"].s() << ' '
            << user["price"] << '\n';
    }

    std::cout << "Bye!";


    return 0;
}
