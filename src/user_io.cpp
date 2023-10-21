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
    cout << "-Client successfully registered." << endl;
}

void printEventRecordNoPrompt() {
    cout << "> Event Record Number: ";
}

void printEventTypePrompt() {
    cout << "> Event Type: ";
}

void printStartDatePrompt() {
    cout << "> Start Date (dd/mm/yy): ";
}

void printEndDatePrompt() {
    cout << "> End Date (dd/mm/yy): ";
}

void printExpectedNumAttendeesPrompt() {
    cout << "> Expected Number Of Attendees: ";
}

void printExpectedBudgetPrompt() {
    cout << "> Expected Budget: ";
}

void printMenuOptionString(MenuOption menuOption) {
    switch (menuOption) {
        case MO_LogIn:
            cout << "Log in";
            break;
        case MO_Quit:
            cout << "Quit";
            break;
        case MO_LogOut:
            cout << "Log out";
            break;
        case MO_RegisterClient:
            cout << "Register client";
            break;
        case MO_CreateOrUpdateEvent:
            cout << "Add event";
            break;
        default:
            cout << "Unknown";
            break;
    }
}

MenuOption queryMenuOptionsFromUser(const vector<MenuOption> &options) {
    if (options.size() == 0) {
        return MO_NullOption;
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
        // cout << "> ";
        cin >> inputString;

        bool isInt = true;
        for (size_t i = 0; i < inputString.size(); i++) {
            if (!isdigit(inputString[i])) {
                isInt = false;
                break;
            }
        }

        if (!isInt) {
            cout << "- Incorrect input. Try again." << endl << "> ";
            continue;
        }

        inputInt = stoi(inputString);
        if (inputInt < minValue || inputInt > maxValue) {
            cout << "- Incorrect input. Try again." << endl << "> ";
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
        cin >> inputString;

        if (inputString.size() < minLength) {
            cout << "- Input is too short. Please try again." << endl << "> ";
            continue;
        }

        if (inputString.size() > maxLength) {
            cout << "- Input is too long. Please try again." << endl << "> ";
            continue;
        }

        runMainLoop = false;
    }

    return inputString;
}

string getDateStringFromUser() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // https://gist.github.com/leimao/418395bf920eb70b2b11fe89d7c1f738
    string inputString;

    bool runLoop = true;
    while (runLoop) {
        cin >> inputString;

        if (inputString.size() != 8) {
            cout << "- Incorrect format. Please try again." << endl;
            cout << "> dd/mm/yy: ";
            continue;
        }

        runLoop = false;
    }

    return inputString;
}
