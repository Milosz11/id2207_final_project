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
 * Encapsulate the functionality for registering a client into the system
 * 
 * @param 
 * 
 * @return a nullptr if the user wants to quit the program prematurely, or a
 *  Client pointer to the heap allocated Client object. The caller is responsible
 *  for freeing the pointer.
*/
void registerClient();
