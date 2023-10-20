#include "../inc/entity_objects.hpp"

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

Role User::getRole() const {
        return _role;
}

Client::Client(const string &recordNumber, const string &fullName, const string &phoneNumber) :
        _recordNumber(recordNumber), _fullName(fullName), _phoneNumber(phoneNumber) { }

void Client::addClient() {

        ifstream ifs("data/data.json");
        json data = json::parse(ifs);

        json client = {
                {"recordNumber", this->_recordNumber},
                {"fullName", this->_fullName},
                {"phoneNumber", this->_phoneNumber}
        };
        data["clients"].push_back(client);
        std::ofstream jsonOut("data/data.json");
        jsonOut << std::setw(4) << data;
        jsonOut.close();

        // cout << "PLACEHOLDER: client add success" << endl;
}

PermissionMatrix::PermissionMatrix() {
        _rolePermissions[GuestUser] = vector<MenuOption> {
                LogIn, Quit
        };
        _rolePermissions[AdministrationDepartmentManager] = vector<MenuOption> {
                LogOut
        };
        _rolePermissions[SeniorCustomerServiceOfficer] = vector<MenuOption> {
                LogOut, RegisterClient
        };
        _rolePermissions[CustomerService] = vector<MenuOption> {
                LogOut, RegisterClient
        };
        // _rolePermissions[AdministrationDepartmentManager] = vector<MenuOption> {LogOut};
        // _rolePermissions[AdministrationDepartmentManager] = vector<MenuOption> {LogOut};
}

const vector<MenuOption> &PermissionMatrix::getPermissions(Role role) {
        return _rolePermissions[role];
}
