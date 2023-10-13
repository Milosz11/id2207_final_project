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

void printUserNamePrompt() {
    cout << "> Username: ";
}

void printPasswordPrompt() {
    cout << "> Password: ";
}
