#include <iostream>
#include <fstream>

#include "json.hpp"
#include "format.hpp"
#include "entity_objects.hpp"
#include "utility.hpp"

using json = nlohmann::json;

/**
 * Encapsulate the functionality for logging a user into the system
*/
User *handleUserLogin(json data);

int main() {

    ifstream ifs("data.json");
    json data = json::parse(ifs);
    json users = data["users"];

    printGreeting();
    User *pUser = handleUserLogin(users);

    if (pUser == nullptr) {
        return 0;
    }

    return 0;
}
