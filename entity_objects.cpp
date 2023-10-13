#include "entity_objects.hpp"

User::User(string &userName, string &password, string &fullName, Role role) :
        _userName(userName), _password(password), _fullName(fullName), _role(role) { }
