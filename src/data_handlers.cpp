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

    printEventRecordNoPrompt();
    inputRecordNumber = getStringFromUserBetweenLength(
        EVENT_RECORD_NO_MIN_LENGTH, EVENT_RECORD_NO_MAX_LENGTH
    );

    bool runClientNoPromptLoop = true;
    while (runClientNoPromptLoop) {
        printClientRecordNoPrompt();
        inputClientRecordNumber = getStringFromUserBetweenLength(
            CLIENT_RECORD_NO_MIN_LENGTH, CLIENT_RECORD_NO_MAX_LENGTH
        );

        if (!checkClientExists(inputClientRecordNumber)) {
            printClientRecordNoNotFound();
            continue;
        }

        runClientNoPromptLoop = false;
    }

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
    string inputTaskId;
    TaskPriority inputPriority;

    bool runEventNoPromptLoop = true;
    while (runEventNoPromptLoop) {
        printEventRecordNoPrompt();
        inputEventRecordNumber = getStringFromUserBetweenLength(
            EVENT_RECORD_NO_MIN_LENGTH, EVENT_RECORD_NO_MAX_LENGTH
        );

        if (!checkEventExists(inputEventRecordNumber)) {
            printEventRecordNoNotFound();
            continue;
        }

        runEventNoPromptLoop = false;
    }

    printTaskId();
    inputTaskId = getStringFromUserBetweenLength(6,8);

    printAssignedSubworkerUsername();
    inputAssignedSubworkerUsername = getStringFromUserBetweenLength(1,1024);

    printTaskDescription();
    inputTaskDescription = getStringFromUserBetweenLength(1,1024);

    queryTaskPriorityFromUser(inputPriority);

    json task = {
        {"eventRecordNumber", inputEventRecordNumber},
        {"assignedTo", inputAssignedSubworkerUsername},
        {"description", inputTaskDescription},
        {"priority", inputPriority},
        {"taskId", inputTaskId}
    };

    addObjectToJson("tasks", task);

}

void createOrUpdateFinancialRequest() {
    string inputRequestingDepartment;
    string inputEventRecordNumber;
    int inputRequiredAmount;
    string inputReason;

    printRequestingDepartmentPrompt();
    inputRequestingDepartment = getStringFromUserBetweenLength(1, 4096);

    bool runEventNoPromptLoop = true;
    while (runEventNoPromptLoop) {
        printEventRecordNoPrompt();
        inputEventRecordNumber = getStringFromUserBetweenLength(
            EVENT_RECORD_NO_MIN_LENGTH, EVENT_RECORD_NO_MAX_LENGTH
        );

        if (!checkEventExists(inputEventRecordNumber)) {
            printEventRecordNoNotFound();
            continue;
        }

        runEventNoPromptLoop = false;
    }

    printRequiredAmountPrompt();
    inputRequiredAmount = getIntFromUser(0, 10000000);

    printFinReqReasonPrompt();
    inputReason = getStringFromUserBetweenLength(1, 4096);

    json finReq = {
        {"requestingDepartment", inputRequestingDepartment},
        {"eventRecordNumber", inputEventRecordNumber},
        {"requiredAmount", inputRequiredAmount},
        {"reason", inputReason},
        {"isAccepted", false}
    };

    addObjectToJson("finRequests", finReq);
    printFinRequestSuccess();
}

void addCommentsToTask() {
    string inputTaskId;
    string inputComment;

    printTaskId();
    inputTaskId = getStringFromUserBetweenLength(6,8);

    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json tasks = data["tasks"];

    // find json task object referring to passed taskId
    for (auto task : tasks) {
        if (inputTaskId == task["taskId"].get<string>()) {
           Task *temp = new Task (
                task["eventRecordNumber"].get<string>(),
                task["assignedTo"].get<string>(),
                task["description"].get<string>(),
                (TaskPriority) task["priority"].get<int>()
            );

            printTaskInfo(*temp);
            delete temp;

            cout << "> New Comment: ";
            inputComment = getStringFromUserBetweenLength(5,1024);

            json newTask = {
                {"eventRecordNumber", task["eventRecordNumber"].get<string>()},
                {"assignedTo", task["assignedTo"].get<string>()},
                {"description", task["description"].get<string>()},
                {"priority", (TaskPriority) task["priority"].get<int>()},
                {"taskId", inputTaskId},
                {"comments", inputComment}
            };

            addObjectToJson("tasks", newTask);
            break;
        }
    }
    cout << "Task Id does not exist";
}

void viewAllTasks() {
    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json tasks = data["tasks"];

    for (auto task : tasks) {
        if (!tasks.empty()) {
            Task *temp = new Task (
                task["eventRecordNumber"].get<string>(),
                task["assignedTo"].get<string>(),
                task["description"].get<string>(),
                (TaskPriority) task["priority"].get<int>(),
                task["comments"].get<string>()
            );

            printFullTaskInfo(*temp);
            delete temp;
        }
    }
}

void viewMyTasks(const string userName) {
    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json tasks = data["tasks"];
    json myTasks;

    // find json task object referring to passed username
    for (auto task : tasks) {
        if (userName == task["assignedTo"].get<string>()) {
            myTasks.push_back(task);
        }
    }

    for (auto myTask : myTasks) {
        if (!myTasks.empty()) {
            Task *temp = new Task (
                myTask["eventRecordNumber"].get<string>(),
                myTask["assignedTo"].get<string>(),
                myTask["description"].get<string>(),
                (TaskPriority) myTask["priority"].get<int>()
            );

            printTaskInfo(*temp);
            delete temp;
        }
    }
}

void addObjectToJson(const string entity, const json object) {

    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    data[entity].push_back(object);
    std::ofstream jsonOut("data/data.json");
    jsonOut << std::setw(4) << data;
    jsonOut.close();
}

bool checkClientExists(string clientRecordNumber) {
    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json clients = data["clients"];

    // find json client object referring to passed clientRecordNumber
    for (auto client : clients) {
        if (clientRecordNumber == client["recordNumber"].get<string>()) {
            return true;
        }
    }
    return false;
}

bool checkEventExists(string eventRecordNumber) {
    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json events = data["events"];

    // find json event object referring to passed eventRecordNumber
    for (auto event : events) {
        if (eventRecordNumber == event["recordNumber"].get<string>()) {
            return true;
        }
    }
    return false;
}

bool checkTaskExists(string eventRecordNumber) {
    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json events = data["events"];

    // find json event object referring to passed eventRecordNumber
    for (auto event : events) {
        if (eventRecordNumber == event["recordNumber"].get<string>()) {
            return true;
        }
    }
    return false;
}