#include "format.hpp"

void printBreak() {
    cout << string(70, '-') << endl;
}

void printEmptyLine() {
    cout << "-" << endl;
}

void printGreeting() {
    printBreak();
    cout << "- Welcome to the SEP system!" << endl;
    printEmptyLine();
}

void printPreLoginMenu() {
    cout << "- Select a menu option:" << endl;
    cout << "- 1. Login" << endl;
    cout << "- 2. Quit" << endl;
    cout << "> ";
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
