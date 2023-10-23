#pragma once

#include "entity_objects.hpp"
#include "user_io.hpp"

#define CLIENT_RECORD_NO_MIN_LENGTH 6
#define CLIENT_RECORD_NO_MAX_LENGTH 8
#define EVENT_RECORD_NO_MIN_LENGTH 6
#define EVENT_RECORD_NO_MAX_LENGTH 8

/**
 * Encapsulate the functionality for logging a user into the system
 * 
 * @param users a json representation object of the 'users' array in the data file
 * 
 * @return a nullptr if the user quit the process of logging in prematurely, or a
 *  User pointer to the heap allocated User object. The caller is responsible
 *  for freeing the pointer.
*/
User *handleUserLogin(const json &users);

/**
 * Encapsulate the functionality for registering a client into the system
*/
void registerClient();

/**
 * Prompt the user for details about creating or updating an event, then update json file
*/
void createOrUpdateEvent();

/**
 * Prompt the user for details about creating or updating a task, then update json file
*/
void createOrUpdateTask();

/**
 * Encapsulate the functionality for adding data to the json database
 * 
 * @param entity the json array in which needs to be updated.
 *  This can be events, users, clients, etc.
 * 
 * @param object json object which should be added to the database
*/
void addObjectToJson(string entity, json object);

/**
 * Check if a client exists in the json database using unique identifier record number.
 * 
 * @param clientRecordNumber a unique identifer for clients in string format
 * 
 * @return true if client is found in json database, otherwise false
*/
bool checkClientExists(string clientRecordNumber);

/**
 * Check if an event exists in the json database using unique identifier record number.
 * 
 * @param eventRecordNumber a unique identifer for events in string format
 * 
 * @return true if event is found in json database, otherwise false
*/
bool checkEventExists(string eventRecordNumber);