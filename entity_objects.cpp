#include <fstream>
#include "entity_objects.hpp"
#include "json.hpp"


using json = nlohmann::json;

User::User(const string &userName, const string &password, const string &fullName, Role role) :
        _userName(userName), _password(password), _fullName(fullName), _role(role) { }

void User::addUser() {
        json user = {
                {"userName", this->_userName},
                {"password", this->_password},
                {"fullName", this->_fullName},
                {"role", this->_role}
        };
}
