#include "../inc/user_io.hpp"

void printHorizontalDivider() {
    cout << "\033[1;32m" << endl;
    cout << string(70, '-') << endl;
}

void printEmptyLine() {
    cout << "-" << endl;
}

void printGreeting() {
    printHorizontalDivider();
    cout << string(20, ' ') << " Welcome to the SEP system!" << endl;
    printHorizontalDivider();
}

void printUserNamePrompt() {
    cout << "> Username: ";
}

void printUserNameDoesNotExist() {
    cout << "- Username was not found. Please try again." << endl;
}

void printPasswordPrompt() {
    cout << "> Password: ";
}

void printPasswordIncorrect() {
    cout << "- Password is incorrect. Please try again." << endl;
}

void printLogInSuccess() {
    cout << "- Login successful!" << endl;
}

void printClientRecordNoPrompt() {
    cout << "> Client Record Number: ";
}

void printClientNamePrompt() {
    cout << "> Client Name: ";
}

void printClientTeleNoPrompt() {
    cout << "> Client Telephone Number: ";
}

void printAddClientSuccess() {
    cout << "Client successfully registered." << endl;
}

void printMenuOptionString(MenuOption menuOption) {
    switch (menuOption) {
        case LogIn:
            cout << "Log in";
            break;
        case Quit:
            cout << "Quit";
            break;
        case LogOut:
            cout << "Log out";
            break;
        case RegisterClient:
            cout << "Register client";
            break;
        default:
            cout << "Unknown";
            break;
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

string getStringFromUserBetweenLength(int minLength, int maxLength) {
    if (minLength > maxLength) {
        swap(minLength, maxLength);
    }

    string inputString;

    bool runMainLoop = true;
    while (runMainLoop) {
        cout << " ";
        cin >> inputString;

        if (inputString.size() < minLength) {
            cout << "Input is too short. Please try again." << endl;
            continue;
        }

        if (inputString.size() > maxLength) {
            cout << "Input is too long. Please try again." << endl;
            continue;
        }

        runMainLoop = false;
    }

    return inputString;
}
