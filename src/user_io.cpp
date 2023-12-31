#include "../inc/user_io.hpp"

void printHorizontalDivider() {
    cout << string(70, '-') << endl;
}

void printEmptyLine() {
    cout << "-" << endl;
}

void printGreeting() {
    cout << "\033[1;32m"; // make text colored
    printHorizontalDivider();
    cout << string(20, ' ') << " Welcome to the SEP system!" << endl;
    printHorizontalDivider();
}

void printUserNamePrompt() {
    cout << "> Username: ";
}

void printUserNameDoesNotExist() {
    cout << "- Username was not found. Please try again." << endl;
}

void printPasswordPrompt() {
    cout << "> Password: ";
}

void printPasswordIncorrect() {
    cout << "- Password is incorrect. Please try again." << endl;
}

void printLogInSuccess() {
    cout << "- Login successful!" << endl;
}

void printClientRecordNoPrompt() {
    cout << "> Client Record Number: ";
}

void printClientNamePrompt() {
    cout << "> Client Name: ";
}

void printClientTeleNoPrompt() {
    cout << "> Client Telephone Number: ";
}

void printAddClientSuccess() {
    cout << "- Client successfully registered." << endl;
}

void printEventRecordNoPrompt() {
    cout << "> Event Record Number: ";
}

void printEventTypePrompt() {
    cout << "> Event Type: ";
}

void printStartDatePrompt() {
    cout << "> Start Date (dd/mm/yy): ";
}

void printEndDatePrompt() {
    cout << "> End Date (dd/mm/yy): ";
}

void printExpectedNumAttendeesPrompt() {
    cout << "> Expected Number Of Attendees: ";
}

void printExpectedBudgetPrompt() {
    cout << "> Expected Budget: ";
}

void printAssignedSubworkerUsername() {
    cout << "> Assign to: ";
}

void printTaskId() {
    cout << "> Task ID: ";
}

void printTaskDescription() {
    cout << "> Task Description: ";
}

void printClientRecordNoNotFound() {
    cout << "Client record number not found. Please enter a different number." << endl;
}

void printEventRecordNoNotFound() {
    cout << "Event record number not found. Please enter a different number." << endl;
}

void printUpdateOrCreateEventSuccess() {
    cout << "- Event successfully created/updated!" << endl;
}

void printRequestingDepartmentPrompt() {
    cout << "> Requesting Department: ";
}

void printRequiredAmountPrompt() {
    cout << "> Required Amount: ";
}

void printFinReqReasonPrompt() {
    cout << "> Reason: ";
}

void printFinRequestSuccess() {
    cout << "- Financial request successfully created!" << endl;
    printHorizontalDivider();
}

void printLoggedInUser(const string &userName, Role role) {
    cout << "You are logged in as: " << userName << " (" << RoleToString(role) << ")" << endl;
}

string RoleToString(Role role) {
    switch (role) {
        case GuestUser:
            return "Guest";
            break;
        case AdministrationDepartmentManager:
            return "Administration Department Manager";
            break;
        case FinancialManager:
            return "Financial Manager";
            break;
        case ProductionManager:
            return "Production Manager";
            break;
        case ServicesManager:
            return "Services Manager";
            break;
        case SeniorCustomerServiceOfficer:
            return "Senior Customer Service Officer";
            break;
        case CustomerService:
            return "Customer Service";
            break;
        case MarketingOfficer:
            return "Marketing Officer";
            break;
        case MarketingAssistant:
            return "Marketing Assistant";
            break;
        case SeniorHRManager:
            return "Senior HR Manager";
            break;
        case HRAssistant:
            return "HR Assistant";
            break;
        case Photographer:
            return "Photographer";
            break;
        case AudioSpecialist:
            return "Audio Specialist";
            break;
        case GraphicDesigner:
            return "Graphic Designer";
            break;
        case Decorations:
            return "Decorations";
            break;
        case ComputerRelated:
            return "Computer Related";
            break;
        case Chef:
            return "Chef";
            break;
        case Waiter:
            return "Waiter";
            break;
        case VicePresident:
            return "Vice President";
            break;
        case Secretary:
            return "Secretary";
            break;
        case Accountant:
            return "Accountant";
            break;
        default:
            return "Unknown";
            break;
    }

    return "Unknown";
}

string PriorityToString(TaskPriority priority) {
   switch (priority) {
        case TP_High:
            return "High";
            break;
        case TP_Medium:
            return "Medium";
            break;
        case TP_Low:
            return "Low";
            break;
        default:
            return "Unknown";
            break;
    }
}

void printMenuOptionString(MenuOption menuOption) {
    switch (menuOption) {
        case MO_LogIn:
            cout << "Log in";
            break;
        case MO_Quit:
            cout << "Quit";
            break;
        case MO_LogOut:
            cout << "Log out";
            break;
        case MO_RegisterClient:
            cout << "Register client";
            break;
        case MO_CreateOrUpdateEvent:
            cout << "Create/update event";
            break;
        case MO_CreateOrUpdateTask:
            cout << "Add task";
            break;
        case MO_CreateFinancialRequest:
            cout << "Create financial request";
            break;
        case MO_UpdateFinancialRequest:
            cout << "Update financial request";
        case MO_ViewMyTasks:
            cout << "View my tasks";
            break;
        case MO_AddCommentsToTask:
            cout << "Add comments to task";
            break;
        case MO_ViewAllTasks:
            cout << "View all tasks";
            break;
        default:
            cout << "Unknown";
            break;
    }
}

void printEventPreferenceString(EventPreference eventPreference) {
    switch (eventPreference) {
        case EP_Decorations:
            cout << "Decorations";
            break;
        case EP_BreakfastLunchDinner:
            cout << "Breakfast, lunch, dinner";
            break;
        case EP_Parties:
            cout << "Parties";
            break;
        case EP_SoftHotDrinks:
            cout << "Soft/hot drinks";
            break;
        case EP_PhotosFilming:
            cout << "Photos/filming";
            break;
        default:
            cout << "Unknown";
            break;
    }
}

void printTaskInfo(const Task task) {
    cout << string(50, '=') << endl;
    cout << "Event id: " << task.getEventRecordNumber() << endl;
    cout << "Task Description: " << task.getTaskDescription() << endl;
    cout << "Task Priority: " << PriorityToString(task.getPriority()) << endl;
    cout << string(50, '=') << endl;
}

void printFullTaskInfo(const Task task) {
    cout << string(50, '=') << endl;
    cout << "Event id: " << task.getEventRecordNumber() << endl;
    cout << "Task Description: " << task.getTaskDescription() << endl;
    cout << "Task Priority: " << PriorityToString(task.getPriority()) << endl;
    cout << "Comments: " << task.getComments() << endl;
    cout << string(50, '=') << endl;
}

MenuOption queryMenuOptionsFromUser(const vector<MenuOption> &options) {
    if (options.size() == 0) {
        return MO_NullOption;
    }

    cout << "Select from the following menu options:" << endl;

    for (int i = 0; i < options.size(); i++) {
        cout << "- " << (i + 1) << ". ";
        printMenuOptionString(options[i]);
        cout << endl;
    }

    int selectedOption = getIntFromUser(1, options.size());

    return options[selectedOption - 1];
}

void queryEventPreferencesFromUser(vector<EventPreference> &selectedPreferences) {
    selectedPreferences.empty();

    vector<EventPreference> preferencesToDisplay = {
        EP_Decorations, EP_BreakfastLunchDinner, EP_Parties, EP_SoftHotDrinks, EP_PhotosFilming
    };

    bool runQueryLoop = true;
    while (runQueryLoop) {
        cout << "Select which preferences to add for the event (0. to finish):" << endl;
        for (int i = 0; i < preferencesToDisplay.size(); i++) {
            cout << "- " << (i + 1) << ". ";
            printEventPreferenceString(preferencesToDisplay[i]);
            cout << "\n";
        }

        int selectedOptionNumber = getIntFromUser(0, preferencesToDisplay.size());
        if (selectedOptionNumber == 0) {
            runQueryLoop = false;
            break;
        }

        int selectedOptionIndex = selectedOptionNumber - 1;

        EventPreference selectedEP = preferencesToDisplay[selectedOptionIndex];
        preferencesToDisplay.erase(preferencesToDisplay.begin() + selectedOptionIndex);
        selectedPreferences.push_back(selectedEP);
    }
}

void queryTaskPriorityFromUser(TaskPriority &selectedPriority) {
    vector<TaskPriority> prioritiesToDisplay = {
        TP_High, TP_Medium, TP_Low
    };

    cout << "> Select which priority to add for the task:" << endl;
    cout << "- 1. High" << endl;
    cout << "- 2. Medium" << endl;
    cout << "- 3. Low" << endl;

    int selectedOptionNumber = getIntFromUser(1, 3);
    selectedPriority = prioritiesToDisplay[selectedOptionNumber-1];
}

void updateFinancialRequest() {
    ifstream ifs("data/data.json");
    json data = json::parse(ifs);
    json finRequests = data["finRequests"];

    cout << "--------------------------------------------------" << endl;
    cout << "0.\n<QUIT>\n--------------------------------------------------" << endl;

    // display each financial request
    int counter = 1;
    vector<json> vecFinRequests;

    for (auto finRequest : finRequests) {
        string eventRecordNumber = finRequest["eventRecordNumber"].get<string>();
        string reason = finRequest["reason"].get<string>();
        string requestingDepartment = finRequest["requestingDepartment"].get<string>();
        int requiredAmount = finRequest["requiredAmount"].get<int>();
        bool isAccepted = finRequest["isAccepted"].get<bool>();
        FinancialRequest fr(
            requestingDepartment, eventRecordNumber, requiredAmount, reason, isAccepted
        );
        vecFinRequests.push_back(finRequest);

        cout << counter << ".\n";
        cout << fr.toString() << endl;

        counter++;
    }

    // get which one user wants to update
    int userInput = getIntFromUser(0, finRequests.size());
    int userInputIndex = userInput - 1;

    if (userInput = 0) {
        return;
    }

    cout << userInputIndex << endl;

    json fr = vecFinRequests.at(userInputIndex);

    cout << "Change status to approved? (y/n): ";

    bool runLoop = true;
    while (runLoop) {
        string input;
        // cin >> input;
        getline(cin, input);


        if (input.compare("y") == 0) {
            fr["isAccepted"] = true;
            runLoop = false;
        }

        if (input.compare("n") == 0) {
            runLoop = false;
        }
    }

    // update json
    data["finRequests"].clear();
    for (auto finReq : vecFinRequests) {
        data["finRequests"].push_back(finReq);
    }
    std::ofstream jsonOut("data/data.json");
    jsonOut << std::setw(4) << data;
    jsonOut.close();
}

int getIntFromUser(int minValue, int maxValue) {
    if (minValue > maxValue) {
        swap(minValue, maxValue);
    }

    string inputString;
    int inputInt = 0;

    bool runMainLoop = true;
    while (runMainLoop) {
        cout << "> ";
        cin >> inputString;

        bool isInt = true;
        for (size_t i = 0; i < inputString.size(); i++) {
            if (!isdigit(inputString[i])) {
                isInt = false;
                break;
            }
        }

        if (!isInt) {
            cout << "- Incorrect input. Try again." << endl;
            continue;
        }

        inputInt = stoi(inputString);
        if (inputInt < minValue || inputInt > maxValue) {
            cout << "- Incorrect input. Try again." << endl;
            continue;
        }

        runMainLoop = false;
    }

    return inputInt;
}

string getStringFromUserBetweenLength(int minLength, int maxLength) {
    if (minLength > maxLength) {
        swap(minLength, maxLength);
    }

    string inputString;

    bool runMainLoop = true;
    while (runMainLoop) {
        getline(cin, inputString);

        if (inputString == ""){
            cout << "> ";
            continue;
        }

        if (inputString.size() < minLength) {
            cout << "- Input is too short. Please try again." << endl << "> ";
            continue;
        }

        if (inputString.size() > maxLength) {
            cout << "- Input is too long. Please try again." << endl << "> ";
            continue;
        }

        runMainLoop = false;
    }

    return inputString;
}

string getDateStringFromUser() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // https://gist.github.com/leimao/418395bf920eb70b2b11fe89d7c1f738
    string inputString;

    bool runLoop = true;
    while (runLoop) {
        cin >> inputString;

        if (inputString.size() != 8) {
            cout << "- Incorrect format. Please try again." << endl;
            cout << "> dd/mm/yy: ";
            continue;
        }

        runLoop = false;
    }

    return inputString;
}
