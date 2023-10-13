#include <string>

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
    User(string &userName, string &password, string &fullName, Role role);

private:
    string _userName;

    string _password;

    string _fullName;

    Role _role;

};
