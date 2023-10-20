#include <iostream>
#include <fstream>

#include "inc/json.hpp"
#include "inc/format.hpp"
#include "inc/entity_objects.hpp"
#include "inc/utility.hpp"

using json = nlohmann::json;

int main() {

    ifstream ifs("data.json");
    json data = json::parse(ifs);
    json users = data["users"];

    printGreeting();

    User *pUser = handleUserLogin(users);
    if (pUser == nullptr) {
        return 0;
    }
    // pUser->addUser();

    delete pUser;

    registerClient();

    return 0;
}
