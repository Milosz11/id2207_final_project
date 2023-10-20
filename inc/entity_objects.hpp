#pragma once

#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

enum MenuOption {
    LogIn,
    Quit,
    LogOut,
    RegisterClient,
    NullOption
};

enum Role {
    GuestUser,
    AdministrationDepartmentManager,
    FinancialManager,
    ProductionManager,
    ServicesManager,
    SeniorCustomerServiceOfficer,
    CustomerService,
    MarketingOfficer,
    MarketingAssistant,
    SeniorHRManager,
    HRAssistant,
    Photographer,
    AudioSpecialist,
    GraphicDesigner,
    Decorations,
    ComputerRelated,
    Chef,
    Waiter,
    VicePresident,
    Secretary,
    Accountant
};

class User {
public:
    User(const string &userName, const string &password, const string &fullName, Role role);

    Role getRole() const;

private:
    string _userName;

    string _password;

    string _fullName;

    Role _role;

};

class Client {
public:
    Client(const string &recordNumber, const string &fullName, const string &phoneNumber);

private:
    string _recordNumber;

    string _fullName;

    string _phoneNumber;

};

class PermissionMatrix {
public:
    PermissionMatrix();

    const vector<MenuOption> &getPermissions(Role role);

private:
    unordered_map<Role, vector<MenuOption>> _rolePermissions;

};
