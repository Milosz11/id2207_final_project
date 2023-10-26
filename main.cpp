#include <iostream>
#include <fstream>

#include "inc/json.hpp"
#include "inc/user_io.hpp"
#include "inc/entity_objects.hpp"
#include "inc/data_handlers.hpp"

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

        printLoggedInUser(pActiveUser->getUserName(), pActiveUser->getRole());
        selectedMenuOption = queryMenuOptionsFromUser(permissionMatrix.getPermissions(pActiveUser->getRole()));

        switch (selectedMenuOption) {
            case MO_LogIn:
                pLoggedInUser = handleUserLogin(users);
                if (pLoggedInUser == nullptr) {
                    break;
                }
                pActiveUser = pLoggedInUser;
                break;
            case MO_Quit:
                runMenuLoop = false;
                break;
            case MO_LogOut:
                pActiveUser = pGuestUser;
                delete pLoggedInUser;
                pLoggedInUser = nullptr;
                break;
            case MO_RegisterClient:
                registerClient();
                break;
            case MO_CreateOrUpdateEvent:
                createOrUpdateEvent();
                break;
            case MO_CreateOrUpdateTask:
                createOrUpdateTask();
                break;
            case MO_CreateOrUpdateFinancialRequest:
                createOrUpdateFinancialRequest();
                break;
            default:
                cout << "Menu option not implemented or known! Closing program." << endl;
                runMenuLoop = false;
                break;
        }
    }

    delete pGuestUser;
    pActiveUser = nullptr;

    return 0;
}
