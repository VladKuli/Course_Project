#pragma once
#ifndef FILEIO_H
#define FILEIO_H

#include "Client.h"
#include "Employee.h"
#include "Account.h"
#include "Branch.h"

bool loadClients(const char* filename, Client** clients, int* numClients);
bool saveClients(const char* filename, Client* clients, int numClients);

bool loadEmployees(const char* filename, Employee** employees, int* numEmployees);
bool saveEmployees(const char* filename, Employee* employees, int numEmployees);

bool loadAccounts(const char* filename, Account** accounts, int* numAccounts);
bool saveAccounts(const char* filename, Account* accounts, int numAccounts);

bool loadBranches(const char* filename, Branch** branches, int* numBranches);
bool saveBranches(const char* filename, Branch* branches, int numBranches);

#endif
