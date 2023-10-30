#pragma once

#include <iostream>
#include <string>

#include "entity_objects.hpp"
#include "data_handlers.hpp"

using namespace std;

void printHorizontalDivider();

void printEmptyLine();

void printGreeting();

void printUserNamePrompt();

void printUserNameDoesNotExist();

void printPasswordPrompt();

void printPasswordIncorrect();

void printLogInSuccess();

void printClientRecordNoPrompt();

void printClientNamePrompt();

void printClientTeleNoPrompt();

void printAddClientSuccess();

void printEventRecordNoPrompt();

void printEventTypePrompt();

void printStartDatePrompt();

void printEndDatePrompt();

void printExpectedNumAttendeesPrompt();

void printExpectedBudgetPrompt();

void printAssignedSubworkerUsername();

void printTaskDescription();

void printTaskId();

void printClientRecordNoNotFound();

void printEventRecordNoNotFound();

void printUpdateOrCreateEventSuccess();

void printRequestingDepartmentPrompt();

void printRequiredAmountPrompt();

void printFinReqReasonPrompt();

void printFinRequestSuccess();

void printLoggedInUser(const string &userName, Role role);

string RoleToString(Role role);

string PriorityToString(TaskPriority priority);

void printMenuOptionString(MenuOption menuOption);

void printEventPreferenceString(EventPreference eventPreference);

void printTaskInfo(const Task task);

void printFullTaskInfo(const Task task);

/**
 * Display a list of menu options to the user and return the selected one.
 * 
 * @param options vector of menu options to display
 * 
 * @return the menu option selected by the user, or MO_NullOption in the case of an empty input vector
*/
MenuOption queryMenuOptionsFromUser(const vector<MenuOption> &options);

/**
 * Queries the user for event preferences and updates the passed vector in place with the 
 * preferences the user selects
 * 
 * @param selectedPreferences after the function call, is updated with the event preferences
 * the user selects
*/
void queryEventPreferencesFromUser(vector<EventPreference> &selectedPreferences);

/**
 * Queries the user for event preferences and updates the passed vector in place with the 
 * preferences the user selects
 * 
 * @param selectedPriority after the function call, is updated with the event preferences
 * the user selects
*/
void queryTaskPriorityFromUser(TaskPriority &selectedPriority);

/**
 * Queries the user for a financial request, return a pointer to a heap allocated object that
 * should be freed the the caller.
*/
void updateFinancialRequest();

/**
 * Gets an integer value input from the user in the range [minValue, maxValue].
 * 
 * @param minValue lower bound, inclusive
 * @param maxValue upper bound, inclusive
 * 
 * @return user inputted int in [minValue, maxValue]
*/
int getIntFromUser(int minValue, int maxValue);

/**
 * Get a string from the user, ensuring its length is between the provided parameters.
 * 
 * @param minLength inclusive
 * @param maxLength inclusive
 * 
 * @return the user inputted string
*/
string getStringFromUserBetweenLength(int minLength, int maxLength);

/**
 * Prompts the user to enter a date with the format: dd/mm/yy
 * 
 * @return a string of the date formatted like dd/mm/yy
*/
string getDateStringFromUser();
