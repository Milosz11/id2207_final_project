#pragma once

#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

#include "json.hpp"

using namespace std;
using json = nlohmann::json;

enum MenuOption {
    MO_LogIn,
    MO_Quit,
    MO_LogOut,
    MO_RegisterClient,
    MO_CreateOrUpdateEvent,
    MO_NullOption
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

enum EventPreference {
    EP_Decorations,
    EP_BreakfastLunchDinner,
    EP_Parties,
    EP_SoftHotDrinks,
    EP_PhotosFilming
};

class User {
public:
    User(const string &userName, const string &password, const string &fullName, Role role);

    string getUserName() const;

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

class Event {
public:
    Event();

private:
    string _recordNumber;

    string _clientRecordNumber;

    string _eventType;

    string _startDate;

    string _endDate;

    size_t _expectedNumberAttendees;

    vector<EventPreference> _preferences;

    size_t _expectedBudget;

};

class Task {
public:
    Task(string eventRecordNumber);

private:
    string _eventRecordNumber;

    string _assignedSubworkerUsername;

};
