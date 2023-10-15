#include <iostream>
#include <fstream>

#include "json.hpp"
#include "format.hpp"
#include "entity_objects.hpp"

using json = nlohmann::json;

/**
 * Encapsulate the functionality for logging a user into the system
*/
User *handleUserLogin(json data);

int main() {

    ifstream ifs("data.json");
    json data = json::parse(ifs);
    json users = data["users"];

    printGreeting();
    User *pUser = handleUserLogin(users);

    if (pUser == nullptr) {
        return 0;
    }

    return 0;
}

User *handleUserLogin(json users) {
    
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
        string secret;

        // user name loop
        while (runUserNameLoop) {
            printUserNamePrompt();
            cin >> inputUserName;
            
            for (auto user:users) {
                if (user["userName"].get<string>() == inputUserName){
                    secret = user["password"].get<string>();
                }
            }

            if (inputUserName == "q") {
                return nullptr;
            } else if (!secret.empty()) {
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
            } else if (inputPassword == secret) {
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
