#include <iostream>

#include "format.hpp"
#include "entity_objects.hpp"

/**
 * Encapsulate the functionality for logging a user into the system
*/
User *handleUserLogin();

int main() {
    User *pUser = handleUserLogin();

    if (pUser == nullptr) {
        return 0;
    }

    return 0;
}

User *handleUserLogin() {
    string username = "user";
    string password = "password";
    
    User *pReturnUser = nullptr;

    printPreLoginMenu();
    string inputOption;
    cin >> inputOption;

    if (inputOption == "2") {
        return nullptr;
    }

    // log in loop
    bool runLogInLoop = true;
    while (runLogInLoop) {
        bool runUserNameLoop = true;
        bool runPasswordLoop = true;
        string inputUserName;
        string inputPassword;

        // user name loop
        while (runUserNameLoop) {
            printUserNamePrompt();
            cin >> inputUserName;

            if (inputUserName == "q") {
                return nullptr;
            } else if (inputUserName == username) {
                runUserNameLoop = false;
            } else {
                printUserNameDoesNotExist();
            }
        }

        // password loop
        while (runPasswordLoop) {
            printPasswordPrompt();
            cin >> inputPassword;

            if (inputPassword == "q") {
                return nullptr;
            } else if (inputPassword == password) {
                printLogInSuccess();
                runPasswordLoop = false;
                runLogInLoop = false;
                // set pReturnUser once json implemented
            } else {
                printPasswordIncorrect();
            }
        }

        printBreak();
    }

    return pReturnUser;
}
