#include "../inc/entity_objects.hpp"

using json = nlohmann::json;

User::User(const string &userName, const string &password, const string &fullName, Role role) :
        _userName(userName), _password(password), _fullName(fullName), _role(role) { }

void User::addUser() {

        ifstream ifs("data.json");
        json data = json::parse(ifs);

        json user = {
                {"userName", this->_userName},
                {"password", this->_password},
                {"fullName", this->_fullName},
                {"role", this->_role}
        };
        data["users"].push_back(user);
        std::ofstream jsonOut("data.json");
        jsonOut << std::setw(4) << data;
        jsonOut.close();
}

Client::Client(const string &recordNumber, const string &fullName, const string &phoneNumber) :
        _recordNumber(recordNumber), _fullName(fullName), _phoneNumber(phoneNumber) { }

void Client::addClient() {

        ifstream ifs("data.json");
        json data = json::parse(ifs);

        json client = {
                {"recordNumber", this->_recordNumber},
                {"fullName", this->_fullName},
                {"phoneNumber", this->_phoneNumber}
        };
        data["clients"].push_back(client);
        std::ofstream jsonOut("data.json");
        jsonOut << std::setw(4) << data;
        jsonOut.close();
}