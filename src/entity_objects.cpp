#include "../inc/entity_objects.hpp"

User::User(const string &userName, const string &password, const string &fullName, Role role) :
        _userName(userName), _password(password), _fullName(fullName), _role(role) { }

string User::getUserName() const {
        return _userName;
}


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
        _rolePermissions[FinancialManager] = vector<MenuOption> {
                MO_LogOut, MO_CreateOrUpdateEvent
        };
        _rolePermissions[ProductionManager] = vector<MenuOption> {
                MO_LogOut, MO_CreateOrUpdateTask, MO_CreateFinancialRequest
        };
        _rolePermissions[ServicesManager] = vector<MenuOption> {
                MO_LogOut, MO_CreateOrUpdateTask, MO_CreateFinancialRequest
        };
        _rolePermissions[SeniorCustomerServiceOfficer] = vector<MenuOption> {
                MO_LogOut, MO_RegisterClient, MO_CreateOrUpdateEvent
        };
        _rolePermissions[CustomerService] = vector<MenuOption> {
                MO_LogOut, MO_RegisterClient, MO_CreateOrUpdateEvent
        };
        _rolePermissions[MarketingOfficer] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[MarketingAssistant] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[SeniorHRManager] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[HRAssistant] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[Photographer] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[AudioSpecialist] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[GraphicDesigner] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[Decorations] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[ComputerRelated] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[Chef] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[Waiter] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[VicePresident] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[Secretary] = vector<MenuOption> {
                MO_LogOut
        };
        _rolePermissions[Accountant] = vector<MenuOption> {
                MO_LogOut
        };
}

const vector<MenuOption> &PermissionMatrix::getPermissions(Role role) {
        return _rolePermissions[role];
}

FinancialRequest::FinancialRequest(string requestingDepartment, string eventRecordNumber, int requiredAmount, 
            string reason, bool isAccepted) : _requestingDepartment(requestingDepartment),
            _eventRecordNumber(eventRecordNumber), _requiredAmount(requiredAmount), _reason(reason),
            _isAccepted(isAccepted) { }

string FinancialRequest::toString() {
        string output;

        output.append("Requesting department: ");
        output.append(_requestingDepartment);
        output.append("\nEvent record number: ");
        output.append(_eventRecordNumber);
        output.append("\nRequired amount: ");
        output.append("_required amount_");
        output.append("\nReason: ");
        output.append(_reason);
        output.append("\nStatus: ");
        output.append(_isAccepted ? "Approved" : "Denied");
        output.append("\n");
        output.append("--------------------------------------------------");
        
        return output;
}

bool FinancialRequest::getIsAccepted() {
        return _isAccepted;
}

void FinancialRequest::setIsAccepted(bool isAccepted) {
        _isAccepted = isAccepted;
}
