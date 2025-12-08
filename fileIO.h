#pragma once
#ifndef FILEIO_H
#define FILEIO_H

#include "../"// Client.h
#include "models/Employee.h" // Employee.h
#include "models/Account.h"// Account.h
#include "models/Transaction.h"// Transaction.h
#include "models/Branch.h"// Branch.h

bool loadClients(const char* filename, Client** clients, int* numClients);
bool saveClients(const char* filename, Client* clients, int numClients);

bool loadEmployees(const char* filename, Employee** employees, int* numEmployees);
bool saveEmployees(const char* filename, Employee* employees, int numEmployees);

bool loadAccounts(const char* filename, Account** accounts, int* numAccounts);
bool saveAccounts(const char* filename, Account* accounts, int numAccounts);

bool loadTransactions(const char* filename, Transaction** transactions, int* numTransactions);
bool saveTransactions(const char* filename, Transaction* transactions, int numTransactions);

bool loadBranches(const char* filename, Branch** branches, int* numBranches);
bool saveBranches(const char* filename, Branch* branches, int numBranches);

#endif
