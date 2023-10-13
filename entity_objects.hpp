#include <string>

using namespace std;

enum Department {Administration, Financial, Production, Services };

class User {
public:
    User(string &userName, string &password, string &fullName, Department department);

private:
    string _userName;

    string _password;

    string _fullName;

    Department _department;

};
