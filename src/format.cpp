#include "../inc/format.hpp"

void printHorizontalDivider() {
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
