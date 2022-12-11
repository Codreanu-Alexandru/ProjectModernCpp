#include <iostream>
#include <numeric>
#include <sstream>
#include <regex>
#include <string>

#include "AuthentificationUtils.h"
#include <cpr/cpr.h>
#include <crow.h>


int  main()
{
    std::cout << "Welcome to the home page!\n";

    int option = -1;
    std::string username;
    std::string password;
    std::string deleteAccAnswer;

    do {

        std::cout << "1. Log in\n";
        std::cout << "2. Create an account\n";
        std::cout << "0. Exit\n";

        std::cout << "\nChoose an option: ";
        std::cin >> option;

        switch (option) {
            
        case 1:
        {
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            while (!correctAuthentication(username, password)) {

                std::cout << "Incorrect username or password. Try again.\n";
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;
            }
            auto userResponse = cpr::Put(
                cpr::Url{ "http://localhost:4960/sendExistingUserToServer" },
                cpr::Payload{
                    { "username", username },
                    { "password", password }
                }
            );

            if (userResponse.status_code == 200 || userResponse.status_code == 201) {
                std::cout << "Logged into your account. \n";

                int loggedOption = -1;

                do {
                    
                    std::cout << "1. Find a match.\n";
                    std::cout << "2. View my profile.\n";
                    std::cout << "3. Delete account.\n";
                    std::cout << "4. Log out.\n";
                    std::cout << "0. Exit\n";

                    std::cout << "\nChoose an option: ";
                    std::cin >> loggedOption;

                    switch (loggedOption) {

                    case 1:
                    {
                        break;
                    }
                    case 2:
                    {
                        break;
                    }
                    case 3:
                    {   
                        std::cout << "\nAre you sure you want to permanently delete this account? Y/N\n";
                        std::cin >> deleteAccAnswer;

                        if (deleteAccAnswer == "Y" || deleteAccAnswer == "y") {
                            auto deleteUserResponse = cpr::Put(
                                cpr::Url{ "http://localhost:4960/deleteUserFromServer" },
                                cpr::Payload{
                                    { "username", username }
                                }
                            );
                            if (deleteUserResponse.status_code == 200 || deleteUserResponse.status_code == 201) {
                                std::cout << "Account successfully deleted.\n";
                                loggedOption = 0;
                            }
                            else {
                                std::cout << "There was a problem sending the user data to the server :(\n";
                            }

                        }

                        break;
                    }
                    case 4:
                    {
                        loggedOption = 0;
                        break;
                    }
                    case 0:
                    {
                        return 0;
                        break;
                    }
                    default:
                    {
                        std::cout << "Please enter a valid option.\n";

                        break;
                    }
                    }
                } while (loggedOption != 0);
            }
            else {
                std::cout << "There was a problem sending the user data to the server :(\n";
            }
            
            break;
        }
        case 2:
        {   
            std::cout << "Enter an username: ";
            std::cin >> username;

            while (existingUser(username))
            {   
                std::cout << "Username unavailable. Try a different one.\n";
                std::cout << "Enter an username: ";
                std::cin >> username;
            }

            std::cout << "Enter a password: ";
            std::cin >> password;

            auto userResponse = cpr::Put(
                cpr::Url{ "http://localhost:4960/sendNewUserToServer" },
                cpr::Payload{
                    { "username", username },
                    { "password", password }
                }
            );

            if (userResponse.status_code == 200 || userResponse.status_code == 201) {
                std::cout << "Created account. \n";
            }
            else {
                std::cout << "There was a problem sending the user data to the server :(\n";
            }
            
            break;
        }
        case 0:
        {
            break;
        }

        default:
        {
            std::cout << "Please enter a valid option.\n";

            break;
        }
        }

    } while (option != 0);
    

    return 0;
}
