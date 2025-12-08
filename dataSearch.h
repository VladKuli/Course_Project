#pragma once
#ifndef DATASEARCH_H
#define DATASEARCH_H

#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Account.h"
#include "../models/Transaction.h"
#include "../models/Branch.h"

Client* searchClientById(Client* clients, int numClients, long id);
Client* searchClientByName(Client* clients, int numClients, const char* name);

Employee* searchEmployeeById(Employee* employees, int numEmployees, long id);
Employee* searchEmployeeByName(Employee* employees, int numEmployees, const char* name);

Account* searchAccountById(Account* accounts, int numAccounts, long id);
Account* searchAccountByNumber(Account* accounts, int numAccounts, int number);

Transaction* searchTransactionById(Transaction* transactions, int numTransactions, long id);
Transaction* searchTransactionByPurpose(Transaction* transactions, int numTransactions, const char* purpose);

Branch* searchBranchById(Branch* branches, int numBranches, long id);
Branch* searchBranchByName(Branch* branches, int numBranches, const char* name);

#endif
