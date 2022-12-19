#include "ClientInfo.h"

//bool correctAuthentication(std::string username, std::string password) {
//
//    auto users = crow::json::load(response.text);
//    for (const auto& user : users) {
//
//        if (user["username"].s() == username) {
//
//            if (user["password"].s() == password) {
//                return true;
//            }
//        }
//    }
//
//    return false;
//}
//
//bool existingUser(std::string username) {
//
//    auto users = crow::json::load(response.text);
//    for (const auto& user : users) {
//
//        if (user["username"].s() == username) {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//void showUsers()
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

ClientInfo::ClientInfo() {

}

ClientInfo::~ClientInfo()
{}

std::vector<std::pair<std::string, std::string>> ClientInfo::setUserInfo() {

	std::vector<std::pair<std::string, std::string>> userInfosCopy;

	auto users = crow::json::load(response.text);
	for (const auto& user : users) {
		userInfosCopy.push_back(std::make_pair(user["username"].s(), user["password"].s()));
	}

	return userInfosCopy;
}

std::vector<std::pair<std::string, std::string>> ClientInfo::getUserInfo() {
	return userInfos;
}
