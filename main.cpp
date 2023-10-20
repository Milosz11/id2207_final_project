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
    
    PermissionMatrix permissionMatrix;
    // At the same time, we have a guest user and a logged in user, if any.
    User *pGuestUser = new User("guest", "guest", "guest", GuestUser);
    User *pLoggedInUser;
    // The relative information displayed is based on what pActiveUser points to.
    // This pointer should not be freed nor the owner of any heap memory.
    User *pActiveUser = pGuestUser;

    MenuOption selectedMenuOption;
    bool runMenuLoop = true;
    while (runMenuLoop) {

        printHorizontalDivider();
        selectedMenuOption = queryMenuOptionsFromUser(permissionMatrix.getPermissions(pActiveUser->getRole()));

        switch (selectedMenuOption) {
            case LogIn:
                pLoggedInUser = handleUserLogin(users);
                if (pLoggedInUser == nullptr) {
                    break;
                }
                pActiveUser = pLoggedInUser;
                break;
            case Quit:
                runMenuLoop = false;
                break;
            case LogOut:
                pActiveUser = pGuestUser;
                delete pLoggedInUser;
                break;
            case RegisterClient:
                //
                break;
            default:
                cout << "Menu option not implemented or known! Closing program." << endl;
                runMenuLoop = false;
                break;
        }
    }

    delete pGuestUser;
    if (pLoggedInUser != nullptr) {
        delete pLoggedInUser;
    }
    pActiveUser = nullptr;

    return 0;
}
