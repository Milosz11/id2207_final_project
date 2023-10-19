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
 * @return a nullptr if the user wants to quit the program prematurely, or a
 *  User pointer to the heap allocated User object. The caller is responsible
 *  for freeing the pointer.
*/
User *handleUserLogin(const json &users);

/**
 * Display a list of menu options to the user and return the selected one.
 * 
 * @param options vector of menu options to display
 * 
 * @return the menu option selected by the user, or NullOption in the case of an empty input vector
*/
MenuOption queryMenuOptions(const vector<MenuOption> &options);
