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
 * @param data ...
*/
User *handleUserLogin(json data);
