#include "../inc/entity_objects.hpp"

User::User(const string &userName, const string &password, const string &fullName, Role role) :
        _userName(userName), _password(password), _fullName(fullName), _role(role) { }

Role User::getRole() const {
        return _role;
}

Client::Client(const string &recordNumber, const string &fullName, const string &phoneNumber) :
        _recordNumber(recordNumber), _fullName(fullName), _phoneNumber(phoneNumber) { }

PermissionMatrix::PermissionMatrix() {
        _rolePermissions[GuestUser] = vector<MenuOption> {
                MO_LogIn, MO_Quit
        };
        _rolePermissions[AdministrationDepartmentManager] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[SeniorCustomerServiceOfficer] = vector<MenuOption> {
                MO_LogOut, MO_RegisterClient, MO_CreateOrUpdateEvent
        };
        _rolePermissions[CustomerService] = vector<MenuOption> {
                MO_LogOut, MO_RegisterClient
        };
        // _rolePermissions[AdministrationDepartmentManager] = vector<MenuOption> {LogOut};
        // _rolePermissions[AdministrationDepartmentManager] = vector<MenuOption> {LogOut};
}

const vector<MenuOption> &PermissionMatrix::getPermissions(Role role) {
        return _rolePermissions[role];
}
