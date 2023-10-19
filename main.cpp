#include <iostream>
#include <fstream>

#include "inc/json.hpp"
#include "inc/format.hpp"
#include "inc/entity_objects.hpp"
#include "inc/utility.hpp"

using json = nlohmann::json;

int main() {

    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json users = data["users"];

    printGreeting();

    User *pUser = handleUserLogin(users);
    if (pUser == nullptr) {
        return 0;
    }

    PermissionMatrix permissionMatrix;
    MenuOption menuOption = queryMenuOptions(permissionMatrix.getPermissions(pUser->getRole()));
    if (menuOption == NullOption) {
        // enter here if no options passed
    }

    delete pUser;

    return 0;
}
