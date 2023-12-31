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
    MO_CreateOrUpdateTask,
    MO_CreateFinancialRequest,
    MO_UpdateFinancialRequest,
    MO_ViewMyTasks,
    MO_AddCommentsToTask,
    MO_ViewAllTasks,
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

enum TaskPriority {
    TP_High,
    TP_Medium,
    TP_Low
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
    Task(const string &eventRecordNumber, const string &assignedSubworkerUsername, 
        const string &taskDescription, const TaskPriority &priority); 

    Task(const string &eventRecordNumber, const string &assignedSubworkerUsername, 
        const string &taskDescription, const TaskPriority &priority, const string &comments); 
        
    string getEventRecordNumber() const;

    string getTaskDescription() const;

    TaskPriority getPriority() const;

    string getComments() const;

private:

    string _taskId;

    string _eventRecordNumber;

    string _assignedSubworkerUsername;

    string _taskDescription;

    TaskPriority _priority;

    string _comments;
};

class FinancialRequest {
public:
    FinancialRequest(string requestingDepartment, string eventRecordNumber, int requiredAmount, 
            string reason, bool isAccepted);

    // i know i could overlead insertion operator but i wanted more possibilty
    string toString();

    bool getIsAccepted();

    void setIsAccepted(bool isAccepted);

public:
    string _requestingDepartment;
    
    string _eventRecordNumber;
    
    int _requiredAmount;
    
    string _reason;

    bool _isAccepted;

};
