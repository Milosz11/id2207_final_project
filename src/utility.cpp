#include "../inc/utility.hpp"

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
    Client *tmpClient = nullptr;

    bool runClientRegisterLoop = true;
    while (runClientRegisterLoop) {
        string inputClientRecordNo;
        string inputClientName;
        string inputClientTelephone;

        printClientRecordNoPrompt();
        cin >> inputClientRecordNo;

        printClientNamePrompt();
        cin >> inputClientName;

        printClientTeleNoPrompt();
        cin >> inputClientTelephone;

        runClientRegisterLoop = false;

        tmpClient = new Client (inputClientRecordNo, inputClientName, inputClientTelephone);
        tmpClient->addClient();

        delete tmpClient;
    }
}

MenuOption queryMenuOptionsFromUser(const vector<MenuOption> &options) {
    if (options.size() == 0) {
        return NullOption;
    }

    cout << "Select from the following menu options: " << endl;

    for (int i = 0; i < options.size(); i++) {
        cout << "- " << (i + 1) << ". ";
        printMenuOptionString(options[i]);
        cout << endl;
    }

    int selectedOption = getIntFromUser(1, options.size());

    return options[selectedOption - 1];
}

int getIntFromUser(int minValue, int maxValue) {
    if (minValue > maxValue) {
        swap(minValue, maxValue);
    }

    string inputString;
    int inputInt = 0;

    bool runMainLoop = true;
    while (runMainLoop) {
        cout << "> ";
        cin >> inputString;

        bool isInt = true;
        for (size_t i = 0; i < inputString.size(); i++) {
            if (!isdigit(inputString[i])) {
                isInt = false;
                break;
            }
        }

        if (!isInt) {
            cout << "- Incorrect input. Try again." << endl;
            continue;
        }

        inputInt = stoi(inputString);
        if (inputInt < minValue || inputInt > maxValue) {
            cout << "- Incorrect input. Try again." << endl;
            continue;
        }

        runMainLoop = false;
    }

    return inputInt;
}
