#pragma once

#include "entity_objects.hpp"
#include "user_io.hpp"

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
