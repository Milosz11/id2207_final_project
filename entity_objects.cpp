#include "entity_objects.hpp"

User::User(string &userName, string &password, string &fullName, Department department) :
        _userName(userName), _password(password), _fullName(fullName), _department(department) { }
