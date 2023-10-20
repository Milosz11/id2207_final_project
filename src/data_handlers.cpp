#include "../inc/data_handlers.hpp"

User *handleUserLogin(const json &users) {
    
    User *pReturnUser = nullptr;

    // log in loop
    bool runLogInLoop = true;
    while (runLogInLoop) {
        bool runUserNameLoop = true;
        bool runPasswordLoop = true;
        string inputUserName;
        string inputPassword;
        json selected_user;         // initialize when correct user is found in database

        // user name loop
        while (runUserNameLoop) {
            cin.clear();
            printUserNamePrompt();
            cin >> inputUserName;
            
            if (inputUserName == "q") {
                return nullptr;
            }

            // find json user object referring to passed username
            for (auto user : users) {
                if (inputUserName == user["userName"].get<string>()) {
                    selected_user = user;
                }
            }

            // if there exists a user with inputted username
            if (!selected_user.empty()) {
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
            }
            
            if (inputPassword == selected_user["password"].get<string>()) {
                printLogInSuccess();
                runPasswordLoop = false;
                runLogInLoop = false;

                pReturnUser = new User(
                        selected_user["userName"].get<string>(),
                        selected_user["password"].get<string>(),
                        selected_user["fullName"].get<string>(),
                        (Role) selected_user["role"].get<int>()
                    );
            } else {
                printPasswordIncorrect();
            }
        }
    }

    return pReturnUser;
}

void registerClient() {
    string inputClientRecordNo;
    string inputClientName;
    string inputClientTelephone;

    printClientRecordNoPrompt();
    inputClientRecordNo = getStringFromUserBetweenLength(6, 8);

    printClientNamePrompt();
    inputClientName = getStringFromUserBetweenLength(1, 1024);

    printClientTeleNoPrompt();
    inputClientTelephone = getStringFromUserBetweenLength(9, 14);

    Client tmpClient(inputClientRecordNo, inputClientName, inputClientTelephone);
    tmpClient.addClient();
}
