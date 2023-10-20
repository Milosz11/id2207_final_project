#pragma once

#include <string>

#include "json.hpp"
#include "format.hpp"
#include "entity_objects.hpp"

using json = nlohmann::json;

using namespace std;

/**
 * Encapsulate the functionality for logging a user into the system
 * 
 * @param users a json representation object of the 'users' array in the data file
 * 
 * @return a nullptr if the user quit the process of logging in prematurely, or a
 *  User pointer to the heap allocated User object. The caller is responsible
 *  for freeing the pointer.
*/
User *handleUserLogin(const json &users);

/**
 * Encapsulate the functionality for registering a client into the system
*/
void registerClient();

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
