#pragma once

#include <iostream>
#include <string>

#include "entity_objects.hpp"

using namespace std;

void printHorizontalDivider();

void printEmptyLine();

void printGreeting();

void printUserNamePrompt();

void printUserNameDoesNotExist();

void printPasswordPrompt();

void printPasswordIncorrect();

void printLogInSuccess();

void printClientRecordNoPrompt();

void printClientNamePrompt();

void printClientTeleNoPrompt();

void printAddClientSuccess();

// printAddUserSuccess

void printMenuOptionString(MenuOption menuOption);

/**
 * Display a list of menu options to the user and return the selected one.
 * 
 * @param options vector of menu options to display
 * 
 * @return the menu option selected by the user, or NullOption in the case of an empty input vector
*/
MenuOption queryMenuOptionsFromUser(const vector<MenuOption> &options);

/**
 * Gets an integer value input from the user in the range [minValue, maxValue].
 * 
 * @param minValue lower bound, inclusive
 * @param maxValue upper bound, inclusive
 * 
 * @return user inputted int in [minValue, maxValue]
*/
int getIntFromUser(int minValue, int maxValue);

/**
 * Get a string from the user, ensuring its length is between the provided parameters.
 * 
 * @param minLength inclusive
 * @param maxLength inclusive
 * 
 * @return the user inputted string
*/
string getStringFromUserBetweenLength(int minLength, int maxLength);
