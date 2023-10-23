#include "../inc/data_handlers.hpp"

User *handleUserLogin(const json &users) {
    
    User *pReturnUser = nullptr;

    // log in loop
    bool runLogInLoop = true;
    while (runLogInLoop) {
        bool runUserNameLoop = true;
        bool runPasswordLoop = true;
        string inputUserName;
        string inputPassword;
        json selected_user;         // initialize when correct user is found in database

        // user name loop
        while (runUserNameLoop) {
            cin.clear();
            printUserNamePrompt();
            cin >> inputUserName;
            
            if (inputUserName == "q") {
                return nullptr;
            }

            // find json user object referring to passed username
            for (auto user : users) {
                if (inputUserName == user["userName"].get<string>()) {
                    selected_user = user;
                }
            }

            // if there exists a user with inputted username
            if (!selected_user.empty()) {
                runUserNameLoop = false;
            } else {
                printUserNameDoesNotExist();
            }
        }

        // password loop
        while (runPasswordLoop) {
            printPasswordPrompt();
            cin >> inputPassword;

            if (inputPassword == "q") {
                return nullptr;
            }
            
            if (inputPassword == selected_user["password"].get<string>()) {
                printLogInSuccess();
                runPasswordLoop = false;
                runLogInLoop = false;

                pReturnUser = new User(
                        selected_user["userName"].get<string>(),
                        selected_user["password"].get<string>(),
                        selected_user["fullName"].get<string>(),
                        (Role) selected_user["role"].get<int>()
                    );
            } else {
                printPasswordIncorrect();
            }
        }
    }

    return pReturnUser;
}

void registerClient() {
    string inputClientRecordNo;
    string inputClientName;
    string inputClientTelephone;

    printClientRecordNoPrompt();
    inputClientRecordNo = getStringFromUserBetweenLength(
        CLIENT_RECORD_NO_MIN_LENGTH, CLIENT_RECORD_NO_MAX_LENGTH
    );

    printClientNamePrompt();
    inputClientName = getStringFromUserBetweenLength(1, 1024);

    printClientTeleNoPrompt();
    inputClientTelephone = getStringFromUserBetweenLength(9, 14);

    json client = {
        {"recordNumber", inputClientRecordNo},
        {"fullName", inputClientName},
        {"phoneNumber", inputClientTelephone}
    };

    addObjectToJson("clients", client);
}

void createOrUpdateEvent() {
    string inputRecordNumber;
    string inputClientRecordNumber;
    string inputEventType;
    string inputStartDate;
    string inputEndDate;
    int inputExpectedNumberAttendees;
    int inputExpectedBugdet;
    vector<EventPreference> inputEventPreferences;

    // we could implement checks that the client record number exists

    printEventRecordNoPrompt();
    inputRecordNumber = getStringFromUserBetweenLength(
        EVENT_RECORD_NO_MIN_LENGTH, EVENT_RECORD_NO_MAX_LENGTH
    );

    printClientRecordNoPrompt();
    inputClientRecordNumber = getStringFromUserBetweenLength(
        CLIENT_RECORD_NO_MIN_LENGTH, CLIENT_RECORD_NO_MAX_LENGTH
    );

    printEventTypePrompt();
    inputEventType = getStringFromUserBetweenLength(1, 1024);

    printStartDatePrompt();
    inputStartDate = getDateStringFromUser();

    printEndDatePrompt();
    inputEndDate = getDateStringFromUser();

    printExpectedNumAttendeesPrompt();
    inputExpectedNumberAttendees = getIntFromUser(0, 100000);

    printExpectedBudgetPrompt();
    inputExpectedBugdet = getIntFromUser(0, 100000000);

    queryEventPreferencesFromUser(inputEventPreferences);

    json event = {
        {"recordNumber", inputRecordNumber},
        {"clientRecordNumber", inputClientRecordNumber},
        {"eventType", inputEventType},
        {"startDate", inputStartDate},
        {"endDate", inputEndDate},
        {"expectedNumberAttendees", inputExpectedNumberAttendees},
        {"expectedBudget", inputExpectedBugdet},
        {"eventPreferences", inputEventPreferences}
    };

    addObjectToJson("events", event);
    printUpdateOrCreateEventSuccess();
}

void createOrUpdateTask() {
    string inputEventRecordNumber;
    string inputAssignedSubworkerUsername;
    string inputTaskDescription;
    TaskPriority inputPriority;

    // we could implement checks that the event record number exists

    printEventRecordNoPrompt();
    inputEventRecordNumber = getStringFromUserBetweenLength(
        EVENT_RECORD_NO_MIN_LENGTH, EVENT_RECORD_NO_MAX_LENGTH
    );

    printAssignedSubworkerUsername();
    inputAssignedSubworkerUsername = getStringFromUserBetweenLength(1,1024);

    printTaskDescription();
    inputTaskDescription = getStringFromUserBetweenLength(1,1024);

    queryTaskPriorityFromUser(inputPriority);

    json task = {
        {"eventRecordNumber", inputEventRecordNumber},
        {"assignedTo", inputAssignedSubworkerUsername},
        {"description", inputTaskDescription},
        {"priority", inputPriority}
    };

    addObjectToJson("tasks", task);

}

void addObjectToJson(const string entity, const json object) {

        ifstream ifs("data/data.json");
        json data = json::parse(ifs);
        data[entity].push_back(object);
        std::ofstream jsonOut("data/data.json");
        jsonOut << std::setw(4) << data;
        jsonOut.close();
}
