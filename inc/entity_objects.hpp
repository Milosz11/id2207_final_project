#pragma once

#include <string>
#include <fstream>

#include "json.hpp"

using namespace std;

enum Role {
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

    void addUser();

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